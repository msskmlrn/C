#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BAD_CHAR 'X';

typedef struct map {
    int width;
    int height;
    char* data;
} map ;

int mlength;

map *load_map(char* filename) {
    map * gmap = malloc(sizeof(map));
    
    int i = 0;
    int length;
    char *load_data(char* filename);
    int is_line_break(char c);
    
    length = get_file_length(filename);
    mlength = length;
    
    gmap->data = (char*)malloc(length+1);
    gmap->data = load_data(filename);
    
    while(is_line_break(((char *)gmap->data)[i]) != 1) {
        gmap->width++;
        ++i;
    }
    
    i = 0;
    
    for (i; i < length; i++) {
        if (is_line_break(gmap->data[i]) == 1) {
            gmap->height++;
        }
    }        
    
    return gmap;
}

char* load_data(char* filename) {
    int length;
    char * buffer = 0;
    FILE *fptr;
    
    length = get_file_length(filename);
    
    if (length > 0) {
        fptr = fopen(filename, "rb");
        
        if (fptr != NULL) {
            fseek (fptr, 0, SEEK_SET);
            buffer = (char *)malloc (length+1);
            
            if (!buffer) {
                printf("Memory error!");
                fclose(fptr);
                return;
            }
            fread(buffer, length, 1, fptr);
            fclose(fptr);
        }
    }
    return buffer;
}

int get_file_length(char* filename) {
    FILE *fptr;
    int length = 0;
    
    fptr = fopen(filename, "rb");
    
    if (fptr != NULL) {
        fseek(fptr, 0, SEEK_END);
        length = ftell(fptr);
        fclose(fptr);
    }
    else {
        return -1; //file could not be read;
    }
    return length;
}

int is_line_break(char c) {
    
    if (c == ('\n') || c == ('\r')) {
        return 1;
    }
    return 0;
}

void print_map (map * the_map) {
    int i = 0;
    
    printf("width: %d", the_map->width);
    printf(", heigth: %d", the_map->height);
    printf("\n");
    
    for(i; i < mlength; ++i) {
        printf("%c", ((char *)the_map->data)[i]);
    }
    
}

char get_char_at(map *the_map, int x, int y) {
    int i = 0;
    int loc;
    int check_position(map *the_map, int x, int y);
    
    if (check_position(the_map, x, y) == 0) {
        return BAD_CHAR;
    }
    
    loc = ((the_map->width + 1) * y) + x; //rivin lopussa on aina \n -merkki, joten lisätään yksi
    
    for(i; i < mlength; i++) {
        if (i == loc) {
            return the_map->data[i];
        }
    }
}

void set_char_at(map *the_map, int x, int y, char val) {
    int i = 0;
    int loc;
    int check_position(map *the_map, int x, int y);
    
    if (check_position(the_map, x, y) == 0) {
        printf("kelvoton positio");
        return;
    }
    
    loc = ((the_map->width + 1) * y) + x; //rivin lopussa on aina \n -merkki, joten lisätään yksi
    
    for(i; i < mlength; i++) {
        if (i == loc) {
            the_map->data[i] = val;
        }
    }
    return;
}

int check_position(map *the_map, int x, int y) {
    if (x > the_map->width)
        return 0; //kelvoton sijainti
    if (y > the_map->height)
        return 0; //kelvoton sijainti
    
    return 1; //sallittu sijainti
}

void flood_fill(map *the_map, char wall) {
    int i = 0;
    int r;
    char c = '0';
    
    for(i; i < mlength; i++) {
        if (the_map->data[i] == ' ') {
            
            r = ( rand() % 10) + 1;
            the_map->data[i] = (c + r);
        }
    }
    return;
}

int main(int argc, char** argv) {
    srand(time(NULL));
    char* c = "map.txt";
    char test;
    struct map * testmap;
    
    testmap = load_map(c);
    print_map(testmap);
    
    test = get_char_at(testmap, 3, 2); //rivi 2, sarake 3
    printf("char: %c", test);
    
    set_char_at(testmap, 3, 2, 'm');
    
    test = get_char_at(testmap, 3, 2); //rivi 2, sarake 3
    printf("char: %c", test);
    
    print_map(testmap);
    
    flood_fill(testmap, '*');
    
    print_map(testmap);
    
    return (EXIT_SUCCESS);
}

