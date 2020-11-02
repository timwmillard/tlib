#include <stdlib.h>

#include "stack.h"

Stack *stack_create()
{
    Stack *s = malloc(sizeof(Stack));

    s->head = NULL;
    s->size = 0;

    return s;
}

void stack_push(Stack *stack, void *data)
{
    StackNode *node = malloc(sizeof(StackNode));
    node->data = data;
    node->next = stack->head;
    stack->head = node;
    stack->size++;
}

void *stack_pop(Stack *stack)
{
    if (!stack->head)
        return NULL;

    StackNode *node = stack->head;
    void *data = node->data;
    stack->head = node->next;
    free(node);
    stack->size--;

    return data;
}

bool stack_is_empty(Stack *stack)
{
    return stack->size == 0;
}

int stack_size(Stack *stack)
{
    return stack->size;
}

void stack_destroy(Stack *stack)
{
    StackNode *ptr = stack->head;

    // Cleanup all the child nodes
    while (ptr) {
        StackNode *tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }

    free(stack);
}
