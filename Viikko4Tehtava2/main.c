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

uint8_t read_lsb(FILE* f) {
    unsigned char buffer;
    unsigned char result;
    int mask = 0x01;
    
    fread(&buffer, 1, 1, f);
    
    if (buffer & mask) {
        result = 1;
    }
    else {
        result = 0;
    }   
    
    return result;
}

uint8_t extract_byte(FILE* f) {
    unsigned char res;
    unsigned char buffer[7];
    int i = 0;
    int result = 0;
    void print_bin(uint32_t n);
    uint8_t read_lsb(FILE* f);
    
    for (i; i < 8; i++) {
        res = read_lsb(f);
        //printf("%d", res);
        buffer[i] = res;
    }
    i = 7;
    printf("\n");
    
    for (i; i >= 0; i--) {
        //printf("%d", buffer[i]);
    }
    
    return buffer;
}

uint32_t read_uint32(FILE* f) {
    unsigned char buffer = 0;
    uint16_t b1, b2, b3, b4;
    
    uint32_t make_32bit(uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4);
    
    fread(&buffer, 1, 1, f);
    b1 = buffer;
    
    fread(&buffer, 1, 1, f);
    b2 = buffer;
    
    fread(&buffer, 1, 1, f);
    b3 = buffer;
    
    fread(&buffer, 1, 1, f);
    b4 = buffer;
    
    //print_bin(make_32bit(b1, b2, b3, b4));
    buffer = make_32bit(b1, b2, b3, b4);
    printf("%d", buffer);
}

uint32_t make_32bit(uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4) {
    
    uint32_t i = (uint32_t) byte4 << 24 | byte3 << 16 | byte2 << 8 | byte1 << 0;
    return i;
}

uint32_t read_pixel_offset(FILE* f) {
    int i = 0;
    int c;
    unsigned char buffer = 0;
    
    for (i; i < 10; i++) {
        c = getc(f);
    }
    
    fread(&buffer, 1, 1, f);
    
    printf("%d", buffer);
    return buffer;
}

int main(int argc, char** argv) {
    
    FILE *fptr;
    int test;
    unsigned char * buffer;
    
    if ((fptr = fopen("whoa.bmp","r")) == NULL) {
	printf ("Can't open file for reading.\n");
        return 1;
    }
    
    //read_lsb(fptr);
    //extract_byte(fptr);
    //read_uint32(fptr);
    
    test = read_pixel_offset(fptr);
    fseek (fptr, test, SEEK_SET);
    
    while (1) {
        test = extract_byte(fptr);
        if (test == '00000000') 
            break;
        printf("%c", test);
    }
    
    fclose(fptr);
    
    return (EXIT_SUCCESS);
}

/*
 
 1396067650
 01010011.00110110.01001101.01000010.
 
 */