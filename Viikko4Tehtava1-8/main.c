#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print_bin(uint32_t n) {
    unsigned int i;
    int count = 0;
    
    i = 1<<(sizeof(n) * 8 - 1);
    
    while (i > 0) {
        if (n & i)
            printf("1");
        else
            printf("0");
        i >>= 1;
        
        count++;
        
        if (count == 8) {
            printf(".");
            count = 0;
        }
        
    }
}

uint16_t make_16bit(uint8_t ls, uint8_t ms) {
    uint16_t result = 0;
    result += (ms << 8);
    result += ls;
    
    return result;
}

uint32_t make_32bit(uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4) {
    uint32_t result = 0;
    result += (byte4 << 24);
    result += (byte3 << 16);
    result += (byte2 << 8);
    result += byte1;
    
    return result;
}

uint8_t read_lsb(FILE* fptr) {
    uint8_t result = 0;
    uint8_t mask = 1;
    result = ((uint8_t)getc(fptr)) & mask;
    return result;
}

uint8_t extract_byte(FILE* fptr) {
    int i = 0;
    uint8_t result = 0;
    uint8_t next_bit;
    
    for(i; i < 8; i++) {
        next_bit = read_lsb(fptr);
        next_bit <<= i;
        result += next_bit;
    }
    return result;
}

uint32_t read_uint32(FILE* fptr) {
    uint8_t b1 = (uint8_t)getc(fptr);
    uint8_t b2 = (uint8_t)getc(fptr);
    uint8_t b3 = (uint8_t)getc(fptr);
    uint8_t b4 = (uint8_t)getc(fptr);
    return make_32bit(b1,b2,b3,b4);
}

uint32_t read_pixel_offset(FILE* fptr) {
    fseek(fptr, 0xa, SEEK_SET);
    return read_uint32(fptr);
}

void reveal_message(FILE* fptr) {
    fseek(fptr, read_pixel_offset(fptr), SEEK_SET);
    uint8_t next_byte;
    while((next_byte = extract_byte(fptr))) {
        printf("%c", (char)next_byte);
    }
    return;
}

int main(int argc, char* argv[]) {
    FILE* fptr;
    
    print_bin(123456789);
    
    if((fptr = fopen("whoa.bmp", "r")) != NULL) {
        reveal_message(fptr);
        fclose(fptr);
    }
    else {
        printf("Couldn't open file!\n");
    }
    
    return EXIT_SUCCESS;
}