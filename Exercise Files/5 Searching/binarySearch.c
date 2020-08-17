#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int16_t binarySearch(int32_t* array, int32_t value, uint16_t size) {
    bool found = false;
    uint16_t lowerIdx = 0;
    uint16_t upperIdx = size - 1;
    uint16_t midPtIdx;

    while (!found && lowerIdx <= upperIdx) {

        midPtIdx = (upperIdx + lowerIdx)/2;

        if (array[midPtIdx] == value) {
            found = true;
        }
        else if (array[midPtIdx] > value) { // Value is on the left side
            upperIdx = midPtIdx - 1;
        } 
        else {
            lowerIdx = midPtIdx + 1;
        }
    }

    if (!found) {
        midPtIdx = -1;
    }
    return midPtIdx;
}


int main () {
    uint32_t data[] = {2,45,67,98,123,321,657,900,1246};

    printf("%i \n\r", binarySearch(data, 98, sizeof(data)/sizeof(data[0])));
    printf("%i \n\r", binarySearch(data, 321, sizeof(data)/sizeof(data[0])));
    printf("%i \n\r", binarySearch(data, 900, sizeof(data)/sizeof(data[0])));
    printf("%i \n\r", binarySearch(data, 74, sizeof(data)/sizeof(data[0])));

    printf("End");

    getchar();
}