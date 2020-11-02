/**
 * TStack - Stack implementation
 * 
 * Author: Tim Millard
 *
 */

#include <stdbool.h>

#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
    void *data;
    struct StackNode *next;
} StackNode;

typedef struct Stack {
    StackNode *head;
    int size;
} Stack;

Stack *stack_create();
void stack_push(Stack *stack, void *data);
void *stack_pop(Stack *stack);
bool stack_is_empty(Stack *stack);
int stack_size(Stack *stack);
void stack_destroy(Stack *stack);

#endif
