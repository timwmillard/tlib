#include <stdlib.h>

#include "queue.h"

Queue *queue_create()
{
    Queue *queue = malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    return queue;
}

void queue_enqueue(Queue *queue, void *data)
{
    QueueNode *node = malloc(sizeof(QueueNode));
    node->data = data;
    node->next = NULL;

    if (queue->rear) {
        queue->rear->next = node;
    } else {
        queue->front = node;
    }
    queue->rear = node;
    queue->size++;
}

void *queue_dequeue(Queue *queue)
{
    if (queue->size <= 0)
        return NULL;
    
    QueueNode *node = queue->front;
    void *data = node->data;

    queue->front = node->next;
    queue->size--;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(node);
    return data;
}

void *queue_peek(Queue *queue)
{
    if (queue->size <= 0)
        return NULL;
    
    return queue->front->data;
}

bool queue_is_empty(Queue *queue)
{
    return queue->size <= 0;
}

int queue_size(Queue *queue)
{
    return queue->size;
}

void queue_destroy(Queue *queue)
{
    QueueNode *ptr = queue->front;

    // Cleanup all the child nodes
    while (ptr) {
        QueueNode *tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }

    free(queue);
}
