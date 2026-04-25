#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct ll {
    struct node *head;
    struct node *tail;
};

int size(struct ll *linked_list) {
    int counter = 0;
    struct node *current = linked_list->head;
    while (current != NULL) {
        counter++;
        current=current->next;
    }
    return counter;
}

bool empty(struct ll *ll) {
    return ll->head == NULL;
}

int value_at(struct ll* linked_list, int index) {
    struct node *current = linked_list->head;
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

void push_front(int value, struct ll *linked_list) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = linked_list->head;
    linked_list->head = newNode;
    if (linked_list->tail == NULL) {
        linked_list->tail = newNode;
    }

}


void pop_front(struct ll *ll) {
    if (ll->head == NULL) {
        exit(-1); // The list is empty itself, so you cannot pop the front value. 
    }
    
    struct node *old_head = ll->head; 

    if(ll->tail == ll->head) {
       ll->head = NULL;
       ll->tail = NULL;
    } else {
        ll->head = ll->head->next;
    }

    free(old_head);
}

void push_back(struct ll *ll, int value) {
    
    struct node *newNode = malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->data = value;

    if (ll->head == NULL) {
        ll->head = newNode;
        ll->tail = newNode;
    } else 
    {
        ll->tail->next = newNode;
        ll->tail = newNode;
    }
}

void pop_back(struct ll *ll) {
    if(ll->head == NULL) {
        exit(-1);
    }
    
    struct node *old_tail = ll->tail;
    struct node *new_tail = NULL;
    struct node *current = ll->head;

    while (current->next != NULL) {
        new_tail = current;
        current = current->next;
    }

    if (new_tail == NULL) {
        ll->head = NULL;
        ll->tail = NULL;
    } else {
        new_tail -> next = NULL;
        ll->tail = new_tail;
    }

    free(old_tail);

}

int front(struct ll *ll) {
    if (ll->head == NULL) {
       return -1;
    }

    return ll->head->data;
}

int back(struct ll *ll) {
    if(ll->tail == NULL) {
        return -1;
    }
    return ll->tail->data;
}

void insert (int value, int index, struct ll *ll) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;

    struct node *current = ll->head;
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
        newNode->next = ll->head;
        ll->head = newNode;
    } else if (current == ll->tail) {
        ll->tail->next = newNode;
        newNode->next = NULL;
        ll->tail = newNode;
    } else {
        newNode->next = current;
        prev->next = newNode;        
    }

}

void erase(int index, struct ll *ll) {
    struct node *current = ll->head;
    struct node *prev = NULL;

    for (int i=0; i<index; i++) {
        if (current != NULL) {
        prev = current;
        current = current->next;
        } else {
            exit(-1);
        }
    }

    if (index == 0){
        ll->head = current->next;
        if (ll->head == NULL) 
        { 
            ll->tail = NULL; 
        }
    } else {
        prev->next = current->next;
    }
    
    if (current == ll->tail) {
        ll->tail = prev;
    }

    free(current);
}

int value_n_from_end(int index, struct ll *ll) {
    struct node *current = ll->head;
    int i=0;
    
    while (current != NULL){
        current = current->next;
        i++;
    }

    int inversed_index = i - index;
    current = ll->head;
    for (int y=0; y<inversed_index; y++) {
        current = current->next;
    }
    return current->data;

}
