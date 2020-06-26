#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define ARRAY_SIZE 15

void printArray(uint8_t* array, uint8_t elements) {
    for (uint8_t i = 0; i < elements; i++) {
        printf("%d ", array[i]);
    }
    printf("\r\n");
}

int main () {
    uint8_t Array[ARRAY_SIZE];
    printf("Hello World\n\r");

    srand(1);
    

    for (uint8_t i = 0; i < ARRAY_SIZE; i++) {
        Array[i] = rand() % 100;
    }

    printArray(Array, ARRAY_SIZE);
    
}