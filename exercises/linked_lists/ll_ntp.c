#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
};

int size(struct node *ll) {
    struct node *current = ll;
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

void pop_front(struct node **ll) {
    
    if (*ll == NULL) {
        exit(-1); // The list is empty itself, so you cannot pop the front value. 
    }

    struct node *old_head = *ll; 
    
    *ll = (*ll)->next;

    free(old_head);
}

void push_back(struct node **ll, int value) {
    
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    
    struct node *current = *ll;
    
    if (current == NULL) {
        *ll = newNode;
        return;
    }
    
    while (current->next != NULL) {
        current=current->next;
    }

    current->next = newNode;
}

void pop_back(struct node **ll) {
    if (*ll == NULL) {
        exit(-1);
    }
    struct node *new_tail = NULL;
    struct node *old_tail = NULL;
    struct node *current = *ll;
    
    while(current->next != NULL){
        new_tail = current;
        current = current->next;
    }
    
    old_tail = current;

    if (new_tail == NULL) {
        *ll = NULL;
        // Only one node!
    } else {
        new_tail->next = NULL;
    }
    
    free(old_tail);
}

int front(struct node *ll) {
    if (ll == NULL) {
       return -1;
    }

    return ll->data;
}

int back(struct node *ll) {
    if (ll == NULL) {
        return -1;
    }

    struct node *current = ll;

    while (current->next != NULL) {
        current = current->next;
    }

    return current->data;

}

void insert(int index, int value, struct node **ll) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    
    struct node *current = *ll;
    struct node *prev = NULL;
    
    for (int i=0; i<index; i++) {
        if (current != NULL) {
            prev = current;
            current = current->next;
        } else {
            exit(-1);
        }    
    }
    
    if (index == 0) {
        newNode->next = *ll;
        *ll = newNode;
    } else {
        newNode->next = current;
        prev->next = newNode;
    }
}

void erase(int index, struct node **ll){
    struct node *current = *ll;
    struct node *prev = NULL;

    for (int i=0; i<index; i++) {
        if (current != NULL) {
            prev = current;
            current = current->next;
        } else {
            exit(-1);
        }
    }

    if (index == 0) {
        *ll = current->next;
    } else {
        prev->next = current -> next;
    }

    free(current);
}

int value_n_from_end(int index, struct node *ll) {
    struct node *current = ll;
    int i=0;
    
    while (current != NULL){
        current = current->next;
        i++;
    }

    int inversed_index = i - index;
    current = ll;
    for (int y=0; y<inversed_index; y++) {
        current = current->next;
    }
    return current->data;

}

void reverse(struct node **ll) {    
    struct node *current = *ll;
    struct node *prev = NULL;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current=next;
    }

    *ll = prev;
}


void remove_value(int value, struct node **ll) {
    struct node *current = *ll;
    struct node *prev = NULL;
    
    while (current != NULL) {
        if(current->data == value) {
            if (prev == NULL){
            *ll = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        return;
    }
        prev = current;
        current = current->next;  
    }
}