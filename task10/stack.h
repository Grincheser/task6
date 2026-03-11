#ifndef STACK_H
#define STACK_H

typedef struct stack_node {
    int data;
    struct stack_node* next;
} stack_node;

typedef struct {
    stack_node* top;
    int size;
} stack;

stack* init_stack();
int push(stack* st, int value);
int pop(stack* st, int* result);
void destroy_stack(stack* st);

#endif