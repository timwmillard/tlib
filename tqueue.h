/**
 * Queue - Queue implementation
 * 
 * Author: Tim Millard
 *
 */

#include <stdbool.h>

#ifndef TQUEUE_H
#define TQUEUE_H

typedef struct TQueueNode {
    void *data;
    struct TQueueNode *next;
} TQueueNode;

typedef struct TQueue {
    TQueueNode *front;
    TQueueNode *rear;
    int size;
} TQueue;

TQueue *tqueue_create();
void tqueue_enqueue(TQueue *queue, void *data);
void *tqueue_dequeue(TQueue *queue);
void *tqueue_peek(TQueue *queue);
bool tqueue_is_empty(TQueue *queue);
int tqueue_size(TQueue *queue);
void tqueue_destroy(TQueue *queue);

#endif
