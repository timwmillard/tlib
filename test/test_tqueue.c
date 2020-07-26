#include <stdio.h>
#include <assert.h>

#include "../tqueue.h"

int main()
{
    TQueue *queue = tqueue_create();

    int data1 = 10;
    int data2 = 20;
    int data3 = 30;

    tqueue_enqueue(queue, &data1);
    assert(tqueue_size(queue) == 1);

    tqueue_enqueue(queue, &data2);
    assert(tqueue_size(queue) == 2);

    tqueue_enqueue(queue, &data3);
    assert(tqueue_size(queue) == 3);

    int *p = tqueue_dequeue(queue);
    assert(*p == 10);
    assert(tqueue_size(queue) == 2);

    p = tqueue_dequeue(queue);
    assert(*p == 20);
    assert(tqueue_size(queue) == 1);


    p = tqueue_dequeue(queue);
    assert(*p == 30);
    assert(tqueue_size(queue) == 0);

    tqueue_destroy(queue);

    printf("*** All tests PASSED *** \n" \
           "\n" \
           "Well done. Happy coding!!!\n");

    return 0;
}