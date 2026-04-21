#include <stdlib.h>

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