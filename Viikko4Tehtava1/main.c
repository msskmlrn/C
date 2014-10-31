#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint16_t make_16bit(uint8_t least_significant, uint8_t most_significant) {
    
    uint16_t i = (uint16_t) most_significant << 8 | least_significant;
    
    return i;
}

uint32_t make_32bit(uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4) {
    
    uint32_t i = (uint32_t) byte4 << 24 | byte3 << 16 | byte2 << 8 | byte1 << 0;
    return i;
}

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

int main(int argc, char** argv) {
    /*
     print_bin(0);
     printf("\n");
     print_bin(1);
     printf("\n");
     print_bin(2);
     printf("\n");
     print_bin(43);
     printf("\n");
     print_bin(123456789);
     printf("\n");
     print_bin(make_16bit(7, 1));
     */
    print_bin(make_32bit(1, 2, 3, 4));
    
    return (EXIT_SUCCESS);
}