#include <stdio.h>
#include <assert.h>

#include "../tstack.h"

int main()
{
    TStack *stack = tstack_create();

    int data1 = 10;
    int data2 = 20;
    int data3 = 30;

    tstack_push(stack, &data1);
    assert(tstack_size(stack) == 1);

    tstack_push(stack, &data2);
    assert(tstack_size(stack) == 2);

    tstack_push(stack, &data3);
    assert(tstack_size(stack) == 3);

    int *p = tstack_pop(stack);
    assert(*p == 30);
    assert(tstack_size(stack) == 2);

    p = tstack_pop(stack);
    assert(*p == 20);
    assert(tstack_size(stack) == 1);


    p = tstack_pop(stack);
    assert(*p == 10);
    assert(tstack_size(stack) == 0);

    printf("*** All tests PASSED *** \n" \
           "\n" \
           "Well done. Happy coding!!!\n");

    return 0;
}