#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_NEIGHBOURS 2

bool visited[MAX_NODES];

typedef struct node{
    int data;
    int index;
    struct node* next[MAX_NEIGHBOURS];
}node;

typedef struct queue{
    node* nodes[MAX_NODES];
    int front_queue;
    int rear_queue;
}queue;

void enqueue(queue* queue, node* node){
    queue->nodes[queue->rear_queue] = node;
    queue->rear_queue++;
}

node* dequeue(queue* queue){
    node* temp = queue->nodes[queue->front_queue];
    queue->front_queue++;
    return temp;
}

void bfs(node* root){
   visited[root->index] = true;
   
   queue* queue = malloc(sizeof(queue));
   queue->front_queue = 0;
   queue->rear_queue = 0;
   enqueue(queue, root);

   while(queue->front_queue != queue->rear_queue){
    node* current = dequeue(queue);
    printf("Visiting node with data: %d\n", current->data);
    
    if (current->next[0] != NULL && visited[current->next[0]->index] != true ) {
        visited[current->next[0]->index] = true;
        enqueue(queue, current->next[0]);
    }

    if (current->next[1] != NULL && visited[current->next[1]->index] != true ) {
        visited[current->next[1]->index] = true;
        enqueue(queue, current->next[1]);
    }
   }

   free(queue);
}