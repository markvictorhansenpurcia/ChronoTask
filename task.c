#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "stack.h"
#include "queue.h"
#include "sort.h"
#include "utils.h"

Task* head = NULL;

int idCounter = 1;

Task* findTaskById(int id) {

    Task* temp = head;

    while (temp) {

        if (temp->id == id)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

void addTask() {

    Task* newTask = (Task*)malloc(sizeof(Task));

    if (!newTask) {
        printf("Memory allocation failed.\n");
        return;
    }

    newTask->id = idCounter++;

    printf("Task Name: ");
    fgets(newTask->name, MAX_NAME, stdin);

    newTask->name[strcspn(newTask->name, "\n")] = '\0';

    printf("Priority: ");
    newTask->priority = getIntInput();

    printf("Deadline: ");
    newTask->deadline = getIntInput();

    newTask->next = head;
    head = newTask;

    enqueue(newTask);

    printf("Task added successfully.\n");
}

void viewTasks() {

    Task* temp = head;

    if (!temp) {
        printf("No tasks available.\n");
        return;
    }

    while (temp) {

        printf("\nID: %d\n", temp->id);
        printf("Name: %s\n", temp->name);
        printf("Priority: %d\n", temp->priority);
        printf("Deadline: %d\n", temp->deadline);

        temp = temp->next;
    }
}

void deleteTask() {

    int id;

    printf("Enter Task ID: ");
    id = getIntInput();

    Task *temp = head;
    Task *prev = NULL;

    while (temp && temp->id != id) {

        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("Task not found.\n");
        return;
    }

    if (!prev)
        head = temp->next;
    else
        prev->next = temp->next;

    push(temp);

    printf("Task deleted.\n");
}

void undoDelete() {

    Task* t = pop();

    if (!t) {

        printf("Nothing to undo.\n");
        return;
    }

    t->next = head;
    head = t;

    printf("Undo successful.\n");
}

void processQueue() {

    Task* t = dequeue();

    if (!t) {

        printf("Queue empty.\n");
        return;
    }

    printf("Processing: %s\n", t->name);

    free(t);
}

void menu() {

    int choice;

    while (1) {

        printf("\n===== CHRONOTASK =====\n");

        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Undo Delete\n");
        printf("5. Process Queue\n");
        printf("6. Sort By Priority\n");
        printf("7. Logout\n");

        printf("Choice: ");

        choice = getIntInput();

        switch (choice) {

            case 1:
                addTask();
                break;

            case 2:
                viewTasks();
                break;

            case 3:
                deleteTask();
                break;

            case 4:
                undoDelete();
                break;

            case 5:
                processQueue();
                break;

            case 6:
                bubbleSortTasks();
                break;

            case 7:
                return;

            default:
                printf("Invalid choice.\n");
        }
    }
}