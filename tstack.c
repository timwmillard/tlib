#include <stdlib.h>

#include "tstack.h"

TStack *tstack_create()
{
    TStack *s = malloc(sizeof(TStack));

    s->head = NULL;
    s->size = 0;

    return s;
}

void tstack_push(TStack *stack, void *data)
{
    TStackNode *node = malloc(sizeof(TStackNode));
    node->data = data;
    node->next = stack->head;
    stack->head = node;
    stack->size++;
}

void *tstack_pop(TStack *stack)
{
    if (!stack->head)
        return NULL;

    TStackNode *node = stack->head;
    void *data = node->data;
    stack->head = node->next;
    free(node);
    stack->size--;

    return data;
}

bool tstack_is_empty(TStack *stack)
{
    return stack->size == 0;
}

int tstack_size(TStack *stack)
{
    return stack->size;
}

void tstack_destroy(TStack *stack)
{
    TStackNode *ptr = stack->head;

    // Cleanup all the child nodes
    while (ptr) {
        TStackNode *tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }

    free(stack);
}
