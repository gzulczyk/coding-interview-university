#include <stdlib.h>

typedef struct node{
    struct node* left;
    struct node* right;
    int data;
} node;

node* insert(node* root, int data){
    if(root == NULL) {
        root = malloc(sizeof(node));
        if(root != NULL) {
            root->data = data;
            root->left = NULL;
            root->right = NULL;
        } else {
            return NULL;
        }
    } else {
        if(data < root->data){
            root->left =  insert(root->left, data);
        }
        else if (data > root->data) {
            root->right = insert(root->right, data);
        }
    }
    
    return root;
}

int get_node_count(node* root){
    if (root == NULL) {
        return 0;
    } else {
        return 1 + get_node_count(root->left) + get_node_count(root->right); // The 1 + is each node counting itself.
    }
}