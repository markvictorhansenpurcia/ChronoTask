#ifndef QUEUE_H
#define QUEUE_H

#include "task.h"

typedef struct {
    Task* front;
    Task* rear;
} Queue;

extern Queue scheduleQueue;

void enqueue(Task* t);
Task* dequeue();

#endif