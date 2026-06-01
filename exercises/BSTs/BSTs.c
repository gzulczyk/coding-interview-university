#include <stdlib.h>
#include <stdbool.h>

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

void print_values(node* root){
    if (root == NULL) {
        return;
    } else {
        print_values(root->left);
        printf("%d\n", root->data);  
        print_values(root->right);      
    }
}

void delete_tree(node * root){
    if(root == NULL) {
        return;
    } else {
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }
}

bool is_in_tree(node* root, int value) {
    if(root == NULL) {
        return false;
    } else {
        if(root->data < value) {
            return is_in_tree(root->right, value);
        }

        else if (root->data > value){
            return is_in_tree(root->left, value);
        }

        else if(root->data == value) {
            return true;
        }
    }
} 