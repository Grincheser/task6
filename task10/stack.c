#include <stdlib.h>
#include "stack.h"

stack* init_stack(void)
{
    stack* new_stack;
    
    new_stack = (stack*)malloc(sizeof(stack));
    if (new_stack)
    {
        new_stack->top = NULL;
        new_stack->size = 0;
    }
    
    return new_stack;
}

int push(stack* st, int value)
{
    int result;
    stack_node* new_node;
    
    result = 0;
    if (st)
    {
        new_node = (stack_node*)malloc(sizeof(stack_node));
        if (new_node)
        {
            new_node->data = value;
            new_node->next = st->top;
            st->top = new_node;
            st->size++;
            result = 1;
        }
    }
    
    return result;
}

int pop(stack* st, int* result_value)
{
    int result;
    stack_node* temp;
    
    result = 0;
    if (st && st->top && result_value)
    {
        temp = st->top;
        *result_value = temp->data;
        st->top = temp->next;
        st->size--;
        free(temp);
        result = 1;
    }
    
    return result;
}

void destroy_stack(stack* st)
{
    stack_node* current;
    stack_node* temp;
    
    if (st)
    {
        current = st->top;
        while (current)
        {
            temp = current;
            current = current->next;
            free(temp);
        }
        free(st);
    }
}