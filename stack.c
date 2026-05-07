#include <stdlib.h>

#include "stack.h"

Stack undoStack = {NULL};

void push(Task* t) {

    t->next = undoStack.top;

    undoStack.top = t;
}

Task* pop() {

    if (!undoStack.top)
        return NULL;

    Task* temp = undoStack.top;

    undoStack.top = temp->next;

    return temp;
}