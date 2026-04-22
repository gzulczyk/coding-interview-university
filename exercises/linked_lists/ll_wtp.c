#include <stdlib.h>
#include <stdbool.h>

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

bool empty(struct ll *ll) {
    return ll->head == NULL;
}

int value_at(struct ll* linked_list, int index) {
    struct node *current = linked_list->head;
    int i = 0;
    
    while (i != index) {
        i++;
        current = current->next;
        
        if (current == NULL) {
        return -1;
        }
    }
        return current->data;
}

void push_front(int value, struct ll *linked_list) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = linked_list->head;
    linked_list->head = newNode;
    if (linked_list->tail == NULL) {
        linked_list->tail = newNode;
    }

}