/**
 * Queue - Queue implementation
 * 
 * Author: Tim Millard
 *
 */

#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode {
    void *data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

Queue *queue_create();
void queue_enqueue(Queue *queue, void *data);
void *queue_dequeue(Queue *queue);
void *queue_peek(Queue *queue);
bool queue_is_empty(Queue *queue);
int queue_size(Queue *queue);
void queue_destroy(Queue *queue);

#endif
