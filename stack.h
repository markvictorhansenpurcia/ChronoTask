#ifndef STACK_H
#define STACK_H

#include "task.h"

typedef struct {
    Task* top;
} Stack;

extern Stack undoStack;

void push(Task* t);
Task* pop();

#endif