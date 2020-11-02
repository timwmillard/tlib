#include <stdio.h>
#include <assert.h>

#include "../stack.h"

int main()
{
    Stack *stack = stack_create();

    int data1 = 10;
    int data2 = 20;
    int data3 = 30;

    stack_push(stack, &data1);
    assert(stack_size(stack) == 1);

    stack_push(stack, &data2);
    assert(stack_size(stack) == 2);

    stack_push(stack, &data3);
    assert(stack_size(stack) == 3);

    int *p = stack_pop(stack);
    assert(*p == 30);
    assert(stack_size(stack) == 2);

    p = stack_pop(stack);
    assert(*p == 20);
    assert(stack_size(stack) == 1);


    p = stack_pop(stack);
    assert(*p == 10);
    assert(stack_size(stack) == 0);

    stack_destroy(stack);

    printf("*** All tests PASSED *** \n" \
           "\n" \
           "Well done. Happy coding!!!\n");

    return 0;
}