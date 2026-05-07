#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

Queue scheduleQueue = {NULL, NULL};

void enqueue(Task* t) {

    Task* copy = (Task*)malloc(sizeof(Task));

    *copy = *t;

    copy->next = NULL;

    if (!scheduleQueue.rear) {

        scheduleQueue.front = scheduleQueue.rear = copy;

    } else {

        scheduleQueue.rear->next = copy;

        scheduleQueue.rear = copy;
    }
}

Task* dequeue() {

    if (!scheduleQueue.front)
        return NULL;

    Task* temp = scheduleQueue.front;

    scheduleQueue.front = temp->next;

    if (!scheduleQueue.front)
        scheduleQueue.rear = NULL;

    return temp;
}