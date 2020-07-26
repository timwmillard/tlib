/**
 * TStack - Stack implementation
 * 
 * Author: Tim Millard
 *
 */

#include <stdbool.h>

#ifndef TSTACK_H
#define TSTACK_H

typedef struct TStackNode {
    void *data;
    struct TStackNode *next;
} TStackNode;

typedef struct TStack {
    TStackNode *head;
    int size;
} TStack;

TStack *tstack_create();
void tstack_push(TStack *stack, void *data);
void *tstack_pop(TStack *stack);
bool tstack_is_empty(TStack *stack);
int tstack_size(TStack *stack);
void tstack_destroy(TStack *stack);

#endif
