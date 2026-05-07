#include <stdio.h>
#include <string.h>

#include "sort.h"
#include "task.h"

void bubbleSortTasks() {

    if (!head || !head->next) {

        printf("Not enough tasks.\n");
        return;
    }

    Task *i, *j;

    int tempId;
    int tempPriority;
    int tempDeadline;

    char tempName[MAX_NAME];

    for (i = head; i != NULL; i = i->next) {

        for (j = i->next; j != NULL; j = j->next) {

            if (i->priority > j->priority) {

                tempId = i->id;
                i->id = j->id;
                j->id = tempId;

                tempPriority = i->priority;
                i->priority = j->priority;
                j->priority = tempPriority;

                tempDeadline = i->deadline;
                i->deadline = j->deadline;
                j->deadline = tempDeadline;

                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);
            }
        }
    }

    printf("Tasks sorted successfully.\n");
}