#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct tail_node {
    struct node *head;
    struct node *tail;
};

void enqueue(struct tail_node *ll, int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (ll->head == NULL) {
        ll->head = newNode;
        ll->tail = newNode;
    } else {
        ll->tail->next = newNode;
        ll->tail = newNode;
    }
}

int dequeue(struct tail_node *ll) {
    if(ll->head == NULL) {
        exit(-1);
    }

    struct node *old_head = ll->head;
    int value = old_head->data;

    if (ll->head == ll->tail) {
        ll->head = NULL;
        ll->tail = NULL;
    } else {
        ll->head = ll->head->next;
    }
    free(old_head);
    return value;
}

bool empty(struct tail_node *ll){
    if (ll->head == NULL) {
        return true;
    } else {
        return false;
    }
}