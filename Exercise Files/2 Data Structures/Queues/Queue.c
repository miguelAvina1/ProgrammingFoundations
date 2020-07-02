#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#if defined (__GNU__)
#define PACKED __attribute__((packed))
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
    queuedData * data;
    void * next;
} node;

typedef struct {
    node * head;
    node * tail;
} queue;


node * createNode (queuedData * data) {
    node * newNode;
    newNode = (node *) malloc (sizeof(node));        // Create node
    // We must allocate memory for the struct this Node is pointing!
    // Otherwise we will have a segmentation fault
    newNode->data = (queuedData *) malloc(sizeof(queuedData));
    memcpy(newNode->data, data, sizeof(queuedData)); // Fill with provided data
    //memcpy(data, data, sizeof(queuedData)); // Fill with provided data
    newNode->next = NULL;
    return newNode;
}

void initQueue(queue * q) {
    q -> head = NULL;
    q -> tail = NULL;
}

void queueInsert(queue * q, node * n) {
    node * head;
    node * next;
    if (q -> head == NULL) {
        q -> head = n;
        q -> tail = n;
    }
    else {
        q -> tail -> next = n;  // Update tail's next
        q -> tail = n;  // replace tail
    } 

/*      Iterating through the queue to insert a new record 
        involves O(n) while just inserting to tail is O(1)
        next = (node *) q -> head;
        while (1) { //Iterating through queue
            if (next -> next == NULL) {
                next -> next = n;
                break;
            } else {
                next = (node *) next->next;
            }
        }  */
}

void queueRemove(queue * q, queuedData * retrievedData) {
    node * node_ptr;
    queuedData * node_data_ptr;
    if (q->head == NULL) {
        printf("Fail. Queue is empty\n\r");
    }
    else {
        memcpy(retrievedData, q->head->data, sizeof(queuedData));
        //memcpy(retrievedNode, q -> head, sizeof(node));  // Copy to provided pointer
        node_ptr = q->head;
        node_data_ptr = q->head->data;  // IMPORTANT, not only free up node's memory but also node's data
        q->head = (node *) q->head->next; // Update head
        free(node_ptr);
        free(node_data_ptr);
    }
}


int main () {

    queue beaconQueue;

    initQueue(&beaconQueue);

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
    queueInsert(&beaconQueue, createNode(&data));

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
    queueInsert(&beaconQueue, createNode(&data2));

    
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
    queueInsert(&beaconQueue, createNode(&data3));
 
    queuedData retrievedData;
   
    while (beaconQueue.head != NULL) {
        queueRemove(&beaconQueue, &retrievedData);
        printf("Barrel ID: %d\n\r", retrievedData.barrelID);
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
    queueInsert(&beaconQueue, createNode(&data4));

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
    queueInsert(&beaconQueue, createNode(&data5));

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
    queueInsert(&beaconQueue, createNode(&data6));


    while (beaconQueue.head != NULL) {
        queueRemove(&beaconQueue, &retrievedData);
        printf("Barrel ID: %d\n\r", retrievedData.barrelID);
    }
/*
    queueRemove(&beaconQueue, &retrievedNode);
    printf("Barrel ID: %d\n\r", retrievedNode.data->barrelID);
    queueRemove(&beaconQueue, &retrievedNode);
    printf("Barrel ID: %d\n\r", retrievedNode.data->barrelID);
    queueRemove(&beaconQueue, &retrievedNode);
    printf("Barrel ID: %d\n\r", retrievedNode.data->barrelID);
*/
    printf("Hello World\n");

}