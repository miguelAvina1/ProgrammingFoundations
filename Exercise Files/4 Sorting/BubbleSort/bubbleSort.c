/*
 * Bubble Sort. Happens in place
 */

#include <stdio.h>
#include <stdint.h>



void bubble_sort(int32_t * array, uint16_t length) {
    int32_t temp;
    for (uint16_t i = 1; i < length; i++) {      // Numero de ciclos 
        for (uint16_t j = 0; j < length - i; j++) {  // Ultimo sample del ciclo
            if (array[j] > array[j+1]) {
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    printf("Hello World\n\r");

    int32_t array[] = {572,213, 87, 65, 45, 35, 32, 12, 7, 2};

    for (int i = 0; i < 10; i++ ) {
        printf("%d ", array[i]);
    }
    printf("\n\r");

    bubble_sort(array, sizeof(array)/sizeof(array[0]));

    for (int i = 0; i < 10; i++ ) {
        printf("%d ", array[i]);
    }

    printf("Press Enter To Exit\n\r");
    getchar();
}

