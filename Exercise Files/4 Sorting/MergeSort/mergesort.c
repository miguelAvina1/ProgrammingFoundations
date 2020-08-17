#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 10

void printArray(uint8_t* array, uint8_t elements) {
    for (uint8_t i = 0; i < elements; i++) {
        printf("%d ", array[i]);
    }
    printf("\r\n");
}


void mergeSortMalloc(uint8_t* array, uint8_t size) {
    if (size > 1) {
        
        uint8_t left_len = size/2;
        uint8_t right_len = size-left_len;
        
        uint8_t* left_part;
        uint8_t* right_part;

        left_part = malloc(left_len);
        right_part = malloc(right_len);

        memcpy(left_part, array, left_len);
        memcpy(right_part, &array[size/2], right_len);

       // printArray(left_part, sizeof(left_part));
       // printArray(right_part, sizeof(right_part));

        mergeSortMalloc(left_part, left_len);
        mergeSortMalloc(right_part, right_len);

        uint8_t i, j, k;
        i = j = k = 0;

        while (i < left_len && j < right_len) {
            if (left_part[i] < right_part[j]) {
                array[k] = left_part[i];
                i += 1;
            } else {
                array[k] = right_part[j];
                j += 1;
            }
            k += 1;
        }

        if (i < left_len) {
            memcpy(&array[k], &left_part[i], left_len - i);
        } else if (j < right_len) {
            memcpy(&array[k], &right_part[j], right_len - j);
        }

        __mingw_free(left_part);
        __mingw_free(right_part);
    }
}


void mergeSort(uint8_t* array, uint8_t size) {
    if (size > 1) {
        // TODO: Replace the sizeof(left_part) for just left_len , same for right
        uint8_t left_len = size/2;
        uint8_t right_len = size-left_len;
        
        uint8_t left_part[left_len];
        uint8_t right_part[right_len];

        memcpy(left_part, array, sizeof(left_part));
        memcpy(right_part, &array[size/2], sizeof(right_part));

       // printArray(left_part, sizeof(left_part));
       // printArray(right_part, sizeof(right_part));

        mergeSort(left_part, sizeof(left_part));
        mergeSort(right_part, sizeof(right_part));

        uint8_t i, j, k;
        i = j = k = 0;

        while (i < sizeof(left_part) && j < sizeof(right_part)) {
            if (left_part[i] < right_part[j]) {
                array[k] = left_part[i];
                i += 1;
            } else {
                array[k] = right_part[j];
                j += 1;
            }
            k += 1;
        }

        if (i < sizeof(left_part)) {
            memcpy(&array[k], &left_part[i], sizeof(left_part) - i);
        } else if (j < sizeof(right_part)) {
            memcpy(&array[k], &right_part[j], sizeof(right_part) - j);
        }

    }
}


int main () {
    uint8_t Array[ARRAY_SIZE];
    printf("Hello World\n\r");

    srand(1);
    

    for (uint8_t i = 0; i < ARRAY_SIZE; i++) {
        Array[i] = rand() % 100;
    }

    printArray(Array, ARRAY_SIZE);
    mergeSortMalloc(Array, ARRAY_SIZE);
    printArray(Array, ARRAY_SIZE);

    printf("Press Enter To Exit\n\r");
    getchar();
}