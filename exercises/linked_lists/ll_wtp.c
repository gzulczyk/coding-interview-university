#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct ll {
    struct node *head;
    struct node *tail;
};

int size(struct ll *linked_list) {
    int counter = 0;
    struct node *current = linked_list->head;
    while (current != NULL) {
        counter++;
        current=current->next;
    }
    return counter;
}