/**
 * Queue implemented using an array instead of linked list.
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 16
#define SEND_THRESHOLD  10

#if defined (__GNU__ )
#define PACKED __attribute__((__packed__))
#else
#define PACKED
#endif



typedef struct PACKED {
    int barrelID;
    int battery;
    int temperature;
    int humidity;
    int pressure;
    int roll;
    int pitch;
    int yaw;
} queuedData;


typedef struct {
    queuedData data[BUFFER_SIZE];
    uint16_t head_index;
    uint16_t tail_index;
} queue;



void queue_init(queue* q) {
    q -> head_index = 0;
    q -> tail_index = 0;
}

uint16_t queue_get_size(queue* q) {
    uint16_t total_nodes;
    if (q->tail_index >= q->head_index) {
        total_nodes = (q->tail_index) - (q->head_index);
    } else {
        total_nodes = (q->tail_index) + (BUFFER_SIZE - (q->head_index));
    }
    return total_nodes;
}

bool queue_is_full(queue* q) {
    uint16_t total_nodes;
    total_nodes = queue_get_size(q);
    return (total_nodes > SEND_THRESHOLD);
}

bool queue_is_empty(queue* q) {
    return (q->head_index == q->tail_index);
}

void queue_insert(queue* q, queuedData* data) {
    memcpy(&((q->data)[q->tail_index]), data, sizeof(queuedData));
    q->tail_index += 1;
    q->tail_index %= BUFFER_SIZE;
}

void queue_remove(queue* q, queuedData* data) {
    if (q->head_index == q->tail_index) {
        printf("Queue is empty! \n\r");
    } else {
        memcpy(data, &((q->data)[q->head_index]), sizeof(queuedData));
        q->head_index += 1;
        q->head_index %= BUFFER_SIZE;
    }
}


queue Barrels_queue;




int main(void) {
    printf("Hello Worl2d\n\r");

    queue_init(&Barrels_queue);
    printf("Queue size %d\n\r", queue_get_size(&Barrels_queue));

    queuedData data = {
        .barrelID = 2,
        .battery = 89,
        .temperature = 29,
        .humidity = 30,
        .pressure = 800000,
        .roll = 180,
        .pitch = 90,
        .yaw = 45,
    };
    queue_insert(&Barrels_queue, &data);
    printf("Queue size %d\n\r", queue_get_size(&Barrels_queue));



    queuedData data2 = {
        .barrelID = 61,
        .battery = 70,
        .temperature = 35,
        .humidity = 45,
        .pressure = 800400,
        .roll = 18,
        .pitch = 95,
        .yaw = 95,
    };
    queue_insert(&Barrels_queue, &data2);
    printf("Queue size %d\n\r", queue_get_size(&Barrels_queue));

    
    queuedData data3 = {
        .barrelID = 161,
        .battery = 170,
        .temperature = 135,
        .humidity = 145,
        .pressure = 80400,
        .roll = 118,
        .pitch = 195,
        .yaw = 195,
    };
    queue_insert(&Barrels_queue, &data3);
       printf("Queue size %d\n\r", queue_get_size(&Barrels_queue));

    queuedData retrievedData;


    while (! queue_is_empty(&Barrels_queue)) {
        queue_remove(&Barrels_queue, &retrievedData);
        printf("Barrel ID: %d\n\r", retrievedData.barrelID);
            printf("Queue size %d\n\r", queue_get_size(&Barrels_queue));

    }


queuedData data4 = {
        .barrelID = 161,
        .battery = 170,
        .temperature = 135,
        .humidity = 145,
        .pressure = 80400,
        .roll = 118,
        .pitch = 195,
        .yaw = 195,
    };
    queue_insert(&Barrels_queue, &data4);
    printf("Queue size %d\n\r", queue_get_size(&Barrels_queue));

    queuedData data5 = {
        .barrelID = 61,
        .battery = 70,
        .temperature = 35,
        .humidity = 45,
        .pressure = 800400,
        .roll = 18,
        .pitch = 95,
        .yaw = 95,
    };
    queue_insert(&Barrels_queue, &data5);
    printf("Queue size %d\n\r", queue_get_size(&Barrels_queue));

    queuedData data6 = {
        .barrelID = 2,
        .battery = 89,
        .temperature = 29,
        .humidity = 30,
        .pressure = 800000,
        .roll = 180,
        .pitch = 90,
        .yaw = 45,
    };
    queue_insert(&Barrels_queue, &data6);
    printf("Queue size %d\n\r", queue_get_size(&Barrels_queue));

    while(!queue_is_full(&Barrels_queue)) {
            queue_insert(&Barrels_queue, &data6);
                printf("Queue size %d\n\r", queue_get_size(&Barrels_queue));

    }

    while (! queue_is_empty(&Barrels_queue)) {
        queue_remove(&Barrels_queue, &retrievedData);
        printf("Barrel ID: %d\n\r", retrievedData.barrelID);
            printf("Queue size %d\n\r", queue_get_size(&Barrels_queue));

    }

    queue_remove(&Barrels_queue, &retrievedData);
    printf("Queue size %d\n\r", queue_get_size(&Barrels_queue));

/*    while (1) {
        queue_insert(&BarrelQueue, &data);
        queue_insert(&BarrelQueue, &data2);
        queue_insert(&BarrelQueue, &data3);
        queue_insert(&BarrelQueue, &data4);
        queue_insert(&BarrelQueue, &data5);
        queue_insert(&BarrelQueue, &data6);
    while (! queue_is_empty(&BarrelQueue)) {
            queue_remove(&BarrelQueue, &retrievedData);
            printf("Barrel ID: %d\n\r", retrievedData.barrelID);
        }
    }

  */  return 0;
}