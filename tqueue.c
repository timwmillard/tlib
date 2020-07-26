#include <stdlib.h>

#include "tqueue.h"

TQueue *tqueue_create()
{
    TQueue *queue = malloc(sizeof(TQueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    return queue;
}

void tqueue_enqueue(TQueue *queue, void *data)
{
    TQueueNode *node = malloc(sizeof(TQueueNode));
    node->data = data;
    node->next = NULL;

    if (queue->rear) {
        queue->rear->next = node;
        queue->rear = node;
    } else {
        queue->rear = node;
        queue->front = node;
    }
    queue->size++;
}

void *tqueue_dequeue(TQueue *queue)
{
    if (queue->size == 0)
        return NULL;
    
    TQueueNode *node = queue->front;
    void *data = node->data;

    queue->front = node->next;
    queue->size--;

    free(node);
    return data;
}

void *tqueue_peek(TQueue *queue)
{
    if (queue->size == 0)
        return NULL;
    
    return queue->front->data;
}

bool tqueue_is_empty(TQueue *queue)
{
    return queue->size > 0;
}

int tqueue_size(TQueue *queue)
{
    return queue->size;
}

void tqueue_destroy(TQueue *queue)
{
    TQueueNode *ptr = queue->front;

    // Cleanup all the child nodes
    while (ptr) {
        TQueueNode *tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }

    free(queue);
}
