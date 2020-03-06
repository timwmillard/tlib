/**
 * TStack - Stack implementation
 * 
 * Author: Tim Millard
 *
 */

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
   if (!stack)
      return 0;
   if (!stack->head)
      return 0;

   TStackNode *node = stack->head;
   void *data = node->data;
   stack->head = node->next;
   free(node);
   stack->size--;

   return data;
}

int tstack_empty(TStack *stack)
{
   if (!stack)
      return 0;
   
   if (stack->head)
      return 1;
   else
      return 0;
}

int tstack_size(TStack *stack)
{
   if (!stack)
      return 0;
   
   return stack->size;
}


void tstack_destroy(TStack *stack)
{
   if (!stack)
      return;

   // while (!stack->head) {
   //    stackNode *node = stack->head;
   // }
   free(stack);
}
