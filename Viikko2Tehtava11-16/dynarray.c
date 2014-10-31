#include <stdio.h>
#include <stdlib.h>

typedef struct dynarray
{
    int* data;
    int size; //tilanne nyt
    int capacity; //kokonaiskapiseetti
} dynarray;

dynarray *dynarray_create(void) 
{
    dynarray *array = malloc(sizeof(dynarray));
    
    if (array) {
        array->size = 0;
        array->data = (int *)malloc(array->capacity*sizeof(int));
        
        if (array->data) {
            array->capacity = 4;
        }
        else {
            free(array);
            array = NULL;
        }
    }
    return array;
}

void dynarray_free(dynarray* parray)
{   
    if (parray) {
        free(parray->data);
        free(parray);   
    }    
}

int dynarray_append(dynarray* parray, int elem)
{
    int success = 1;
    
    if ((parray->size + 1) == parray->capacity) {
        
        parray->data = (int *)realloc(parray->data, (parray->capacity * 2) * sizeof(int));
        if (parray != NULL) {
            success = 1;
            parray->capacity *= 2;
        } 
        else {
            success = 0;
        } 
    }
    if (success == 1) {
        parray->data[parray->size] = elem;
        parray->size += 1;
    }
    
    return success;
}

int dynarray_get(dynarray* parray, int position) 
{   
    if (position < parray->size) {
        return parray->data[position];
    }
    return -1; //virheellinen sijainti annettu
}



int main()
{
    int i;
    dynarray *darray;
    
    
    darray = dynarray_create();
    dynarray_free(darray);
    
    darray = dynarray_create();
    dynarray_free(darray);
    
    darray = dynarray_create();
    dynarray_free(darray);
    
    darray = dynarray_create();
    dynarray_free(darray);
    
    darray = dynarray_create();
    dynarray_free(darray);
    
    darray = dynarray_create();
    dynarray_free(darray);
    
    darray = dynarray_create();
    dynarray_free(darray);
    
    darray = dynarray_create();
    
    dynarray_append(darray, 0);
    dynarray_append(darray, 1);
    dynarray_append(darray, 2);
    dynarray_append(darray, 3);
    dynarray_append(darray, 4);
    dynarray_append(darray, 5);
    dynarray_append(darray, 6);
    dynarray_append(darray, 7);
    dynarray_append(darray, 8);
    dynarray_append(darray, 9);
    dynarray_append(darray, 10);
    dynarray_append(darray, 11);
    dynarray_append(darray, 12);
    dynarray_append(darray, 13);
    dynarray_append(darray, 14);
    dynarray_append(darray, 15);
    
    for (i = 0; i < 20; i++) {
        printf("%d ", dynarray_get(darray, i));
    }
    
    dynarray_free(darray);
    
    return 0;
}

/*
 0 0 0 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 ==15861== 
 ==15861== FILE DESCRIPTORS: 3 open at exit.
 ==15861== Open file descriptor 2: /dev/pts/1
 ==15861==    <inherited from parent>
 ==15861== 
 ==15861== Open file descriptor 1: /dev/pts/1
 ==15861==    <inherited from parent>
 ==15861== 
 ==15861== Open file descriptor 0: /dev/pts/1
 ==15861==    <inherited from parent>
 ==15861== 
 ==15861== 
 ==15861== HEAP SUMMARY:
 ==15861==     in use at exit: 0 bytes in 0 blocks
 ==15861==   total heap usage: 19 allocs, 19 frees, 352 bytes allocated
 ==15861== 
 ==15861== All heap blocks were freed -- no leaks are possible
 */