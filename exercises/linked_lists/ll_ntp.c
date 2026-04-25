#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
};

int size(struct node *ll) {
    struct node *current = ll;
    int counter = 0;
    while (current != NULL) {
        counter++;
        current=current->next;
    }
    
    return counter;
}

bool empty(struct node *ll) {
    return ll == NULL;
}

int value_at(struct node *ll, int index) {
    struct node *current = ll;
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


void push_front(int value, struct node **ll) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = *ll;
    *ll = newNode;
}

void pop_front(struct node **ll) {
    
    if (*ll == NULL) {
        exit(-1); // The list is empty itself, so you cannot pop the front value. 
    }

    struct node *old_head = *ll; 
    
    *ll = (*ll)->next;

    free(old_head);
}

void push_back(struct node **ll, int value) {
    
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    
    struct node *current = *ll;
    
    if (current == NULL) {
        *ll = newNode;
        return;
    }
    
    while (current->next != NULL) {
        current=current->next;
    }

    current->next = newNode;
}