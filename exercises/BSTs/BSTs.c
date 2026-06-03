#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h> 

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
    return false;
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

node* delete_node(node* root, int value) {
    if (root == NULL) {
        return NULL;
    } else {
        
        // Find value

        if(root->data < value) {
            root->right = delete_node(root->right, value);
            return root;
        }

        else if (root->data > value){
            root->left = delete_node(root->left, value);
            return root;
        }

        else if(root->data == value) {

        // No children
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // 1 child 
        if((root->left != NULL && root->right == NULL)) {
            node* temp = root->left;
            free(root);
            return temp;
        }

        if(root->left == NULL && root->right != NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        }

        // 2 children
        root->data = get_min(root->right);
        root->right = delete_node(root->right, root->data);
        return root;

        }
    }

    return root;
}

int get_successor(node* root, int value, int successor){
    if (root == NULL) {
        return -1;
    } else {
        if (value < root->data) {
            successor = root->data;
            return get_successor(root->left, value, successor);
        } else if (value > root->data) {
             return get_successor(root->right, value, successor);   
        } else if (value == root->data) {
            if(root->right == NULL) {
                return successor;
            } else if (root->right != NULL) {
                return get_min(root->right);
            }
        }
    }
    return successor;
}

int main(){
    
    // Insert test
    node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    print_values(root);

    // get_node_count test
    assert(get_node_count(root) == 4);

    // delete_tree test 
    delete_tree(root);
    root = NULL;
    assert(get_node_count(root) == 0);

    // is_in_tree test
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    assert(is_in_tree(root, 1) == true);
    assert(is_in_tree(root, 23) == false);

    // get_height
    assert(get_height(root) == 2);
}