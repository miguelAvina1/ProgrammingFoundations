#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
	uint8_t* data;
	uint16_t size;
	uint16_t index;
	uint16_t elements;
} circularBuffer8;




void circBuffer_Init(circularBuffer8* c_buffer, uint16_t length) {
    c_buffer->data = calloc(sizeof(uint8_t), length);
    if (c_buffer->data == NULL) {
        printf("circBuffer_Init() Error Mem Allocation\n\r");
        while(1);
    }
    c_buffer->size = length;
    c_buffer->index = 0;
}


void circBuffer_Add(circularBuffer8* c_buffer, uint8_t data) {
    c_buffer->data[c_buffer->index] = data;
    c_buffer->index++;
    c_buffer->index %= c_buffer->size;
    if (c_buffer->elements < c_buffer->size) {
        c_buffer->elements++;
    } else {
        printf("OverWritting\n\r");
    }
}


bool circBuffer_isFull(circularBuffer8* c_buffer) {
    return c_buffer->elements == c_buffer->size;
}

uint8_t circBuffer_Remove(circularBuffer8* c_buffer) { // Will return zeros when empty
    uint8_t temp;
    c_buffer->index--;
    if (c_buffer->index == 0xFFFF) {
        c_buffer->index = c_buffer->size - 1;
    } 
    temp = c_buffer->data[c_buffer->index];
    c_buffer->data[c_buffer->index] = 0;
    if (c_buffer->elements != 0) {
        c_buffer->elements--;
    } else {
        printf("Buffer is empty\n\r");
    }
    return temp;
}









circularBuffer8 myBuffer;

int main(void) {

    bool full;
    circBuffer_Init(&myBuffer, 5);

    full = circBuffer_isFull(&myBuffer);
    printf("Empty: %d\n\r", full);

    circBuffer_Add(&myBuffer, 10);
    circBuffer_Add(&myBuffer, 7);
    circBuffer_Add(&myBuffer, 25);


    for(int i = 0; i < 5; i++) {
        printf("%d ", myBuffer.data[i]);
    }
    full = circBuffer_isFull(&myBuffer);
    printf("Empty: %d\n\r", full);


    printf("\n\r");
    circBuffer_Add(&myBuffer, 54);
    circBuffer_Add(&myBuffer, 1);
        full = circBuffer_isFull(&myBuffer);
    printf("Empty: %d\n\r", full);
    circBuffer_Add(&myBuffer, 85);
    
    circBuffer_Add(&myBuffer, 74);
    full = circBuffer_isFull(&myBuffer);
    printf("Empty: %d\n\r", full);
    for(int i = 0; i < 5; i++) {
        printf("%d ", myBuffer.data[i]);
    }
    printf("\n\r");
    full = circBuffer_isFull(&myBuffer);
    printf("Empty: %d\n\r", full);
    circBuffer_Add(&myBuffer, 98);
    circBuffer_Add(&myBuffer, 102);

    for(int i = 0; i < 5; i++) {
        printf("%d ", myBuffer.data[i]);
    }
    printf("\n\r");


    uint8_t myData;
    for(int i = 0; i < 3; i++) {
        printf("%d ", circBuffer_Remove(&myBuffer));
    }
    printf("\n\r");
        full = circBuffer_isFull(&myBuffer);
    printf("Empty: %d\n\r", full);
    for(int i = 0; i < 5; i++) {
        printf("%d ", myBuffer.data[i]);
    }
    printf("\n\r");
    full = circBuffer_isFull(&myBuffer);
    printf("Empty: %d\n\r", full);

    return 0;
}