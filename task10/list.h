#ifndef LIST_H
#define LIST_H

#include "door_struct.h"

typedef struct node {
    struct door door;
    struct node* next;
} node;

node* init(struct door door);
node* add_door(node* elem, struct door door);
node* find_door(int door_id, node* root);
node* remove_door(node* elem, node* root);
void destroy(node* root);

#endif