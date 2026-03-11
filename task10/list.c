#include <stdlib.h>
#include "list.h"

node* init(struct door door)
{
    node* new_node;
    
    new_node = (node*)malloc(sizeof(node));
    if (new_node)
    {
        new_node->door = door;
        new_node->next = NULL;
    }
    
    return new_node;
}

node* add_door(node* elem, struct door door)
{
    node* result;
    node* new_node;
    
    result = NULL;
    if (elem)
    {
        new_node = (node*)malloc(sizeof(node));
        if (new_node)
        {
            new_node->door = door;
            new_node->next = elem->next;
            elem->next = new_node;
            result = new_node;
        }
    }
    
    return result;
}

node* find_door(int door_id, node* root)
{
    node* current;
    node* result;
    
    result = NULL;
    current = root;
    while (current && !result)
    {
        if (current->door.id == door_id)
        {
            result = current;
        }
        current = current->next;
    }
    
    return result;
}

node* remove_door(node* elem, node* root)
{
    node* result;
    node* prev;
    node* current;
    
    result = root;
    if (root && elem)
    {
        if (root == elem)
        {
            result = root->next;
            free(root);
        }
        else
        {
            prev = NULL;
            current = root;
            while (current && current != elem)
            {
                prev = current;
                current = current->next;
            }
            
            if (current == elem)
            {
                prev->next = elem->next;
                free(elem);
            }
        }
    }
    
    return result;
}

void destroy(node* root)
{
    node* current;
    node* temp;
    
    current = root;
    while (current)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
}