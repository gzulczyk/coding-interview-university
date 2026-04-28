#include <stdlib.h>

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