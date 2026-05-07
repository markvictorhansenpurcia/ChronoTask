#ifndef TASK_H
#define TASK_H

#define MAX_NAME 50

typedef struct Task {
    int id;
    char name[MAX_NAME];
    int priority;
    int deadline;
    struct Task* next;
} Task;

extern Task* head;
extern int idCounter;

void addTask();
void viewTasks();
void deleteTask();
void processQueue();
void undoDelete();

Task* findTaskById(int id);

void menu();

#endif