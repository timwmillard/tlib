#include <stdio.h>
#include <assert.h>

#include "../queue.h"

int main()
{
    Queue *queue = queue_create();

    int data1 = 10;
    int data2 = 20;
    int data3 = 30;

    queue_enqueue(queue, &data1);
    assert(queue_size(queue) == 1);

    queue_enqueue(queue, &data2);
    assert(queue_size(queue) == 2);

    queue_enqueue(queue, &data3);
    assert(queue_size(queue) == 3);

    int *p = queue_dequeue(queue);
    assert(*p == 10);
    assert(queue_size(queue) == 2);

    p = queue_dequeue(queue);
    assert(*p == 20);
    assert(queue_size(queue) == 1);


    p = queue_dequeue(queue);
    assert(*p == 30);
    assert(queue_size(queue) == 0);

    queue_destroy(queue);

    printf("*** All tests PASSED *** \n" \
           "\n" \
           "Well done. Happy coding!!!\n");

    return 0;
}