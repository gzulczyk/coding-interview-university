#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
};

int size(struct node *ll) {
    struct node* current = ll;
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