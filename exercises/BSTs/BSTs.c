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

int get_height(node* root){
    if(root == NULL) {
        return -1;
    } else{
        int left_side = get_height(root->left);
        int right_side = get_height(root->right);

        return ((left_side > right_side) ? left_side : right_side) + 1;
    }
}

int get_min(node* root){
    if(root == NULL) {
        return -1;
    } else{
        if(root->left == NULL){
            return root->data;
        }
        return get_min(root->left);
    }
}

int get_max(node* root){
    if(root == NULL) {
        return -1;
    } else {
        if (root->right == NULL){
            return root->data;
        }
        return get_max(root->right);
    }
}

bool is_binary_search_tree(node* root, int min, int max){
    if(root == NULL){
        return true;
    } else {
        if (root->data <= min || root->data >= max) {
            return false;
        }
        return is_binary_search_tree(root->left, min, root->data) && is_binary_search_tree(root->right, root->data, max);
    }
}