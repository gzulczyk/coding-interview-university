#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_NODES 100
#define MAX_NEIGHBOURS 2

typedef struct node{
    int index;
    int data;
    struct node* next[MAX_NEIGHBOURS];
} node;

bool visited[MAX_NODES];

// DFS traversal starting from root node, marks visited nodes and prints data.
void dfs(node* root, int index){
    if (!visited[index]) {
    visited[index] = true;

    printf("Visiting node with data: %d\n", root->data);
    
    if(root->next[0] != NULL){
        dfs(root->next[0], root->next[0]->index);
    }

    if(root->next[1] != NULL){
        dfs(root->next[1], root->next[1]->index);
    }

}
}

int main() {
    node* root = malloc(sizeof(node));
    root->data = 0;
    root->index = 0;
    root->next[0] = NULL;
    root->next[1] = NULL;
    
    node* node1 = malloc(sizeof(node));
    node1->data = 2;
    node1->index = 1;
    node1->next[0] = NULL;
    node1->next[1] = NULL;
    
    node* node2 = malloc(sizeof(node));
    node2->data = 7;
    node2->index = 2;
    node2->next[0] = NULL;
    node2->next[1] = NULL;

    root->next[0] = node1;
    root->next[1] = node2;

    dfs(root, root->index);
    free(root);
    free(node1);
    free(node2);
}