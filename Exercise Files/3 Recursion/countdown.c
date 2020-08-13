/**
 * Implementing a recursive countdown.
 */

#include <stdio.h>
#include <stdint.h>


void countdown(uint16_t x) {
    if (x == 0) {
        printf("%d\n\r", x);
        return;
    } else {
        printf("%d ... \n\r", x);
        countdown(x-1);
    }
}


int main () {
    printf("Hello World \n\r");
    printf("Starting countdown\n\r");
    countdown(10);
}
