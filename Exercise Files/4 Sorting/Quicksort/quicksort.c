#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void print_array(int32_t* array, uint16_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\r");
}

void quick_sort(int32_t* array, int16_t lower, int16_t upper) {  // VERY IMPORTANT TO KEEP UPPER AND LOWER SIGNED!!!!!
    
    if (lower < upper) {
    bool done = false;
    int16_t last_value = upper;
    int16_t first_value = lower;
    int32_t temp;
    int16_t pivotIndex = lower;
    int32_t pivotValue = array[lower];
    lower += 1;  // To start after Pivot Index

    while (!done) {
        while(lower <= upper && array[lower] < pivotValue ) {
            lower += 1;
        }

        while(upper >= lower && array[upper] > pivotValue) {
            upper -= 1;
        }

        if (upper < lower) {
            done = true;
        } else {
            temp = array[upper];            // Swap values
            array[upper] = array[lower];
            array[lower] = temp;
        }
    }

    temp = array[pivotIndex];           // Intercambiar viejo pivot en donde quedo el upper
    array[pivotIndex] = array[upper];
    array[upper] = temp;

    pivotIndex = upper;
    // New pivot is at upper index and in its final place. Now order things to right and left of pivot
    quick_sort(array, first_value, pivotIndex - 1);
    quick_sort(array, pivotIndex+1, last_value);
    
    }
    

}



void do_quicksort(int32_t* array, uint16_t size) {
    quick_sort(array, 0, size-1);


}

int main() {
    int32_t values[] = {3,54,57,85,97,234,93,69,28,056,36,96};

    print_array(values, sizeof(values)/sizeof(values[0]));
    do_quicksort(values, sizeof(values)/sizeof(values[0]));
    print_array(values, sizeof(values)/sizeof(values[0]));


    printf("Press Enter to Exit\n\r");
    getchar();
}