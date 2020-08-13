/*
 * Using recursion to implement power and factorial functions
 */


#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>


int power(uint16_t base, uint16_t exponent) {
    uint16_t result;
    result = 1;
    if (exponent == 0) {
        return result;
    }
    for (int i = 0; i < exponent; i ++) {
        result *= base;
    }
    return result;
}


uint32_t power_recursive (uint16_t base, uint16_t exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return base * power(base, exponent-1);
    }
}

void flush() {
    int c;
    while(1) {
        c = fgetc(stdin);
        if(c == EOF || c == '\n') break;
    }
}

uint32_t factorial (uint16_t number) {
    uint32_t result = 1;
    while(number > 1) {
        result *= number;
        number -= 1;
    }
    return result;
}

uint32_t factorial_recursive (uint16_t number) {
    if (number > 1) {
        return number * factorial_recursive(number - 1);
    } else {
        return 1;
    }
}

int main() {
    uint16_t base;
    uint16_t exponent;
    uint16_t factorial_number;
    printf("Base address: %x", &base);
    printf("Exponent address: %x", &exponent);
    printf("Enter base\r\n");
    scanf(" %"SCNu16"", &base);
    flush();

    printf("Enter exponent\n\r");
    scanf(" %"SCNu16"", &exponent);
    

    printf("Hello World\n\r");
    printf("%d, %d, %d\n\r", base, exponent, power(base, exponent)) ;
    printf("(recursively)%d, %d, %d\n\r", base, exponent, power_recursive(base, exponent)) ;

    
    printf("Enter number for factorial\r\n");
    scanf(" %"SCNu16"", &factorial_number);
    printf("Factorial of %d is %d\n\r", factorial_number, factorial(factorial_number)) ;

    printf("Factorial (recursively) of %d is %d\n\r", factorial_number, factorial_recursive(factorial_number)) ;



    //scanf("%d", base);

}