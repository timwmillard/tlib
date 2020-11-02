CC=clang
RM=rm

all : stack.o queue.o

stack.o : stack.c
	${CC} -o stack.o -c stack.c

queue.o : queue.c
	${CC} -o queue.o -c queue.c

test: test/test_stack test/test_queue

test/test_stack: test/test_stack.o stack.o
	${CC} -o test/test_stack stack.o test/test_stack.o

test/test_queue: test/test_queue.o queue.o
	${CC} -o test/test_queue queue.o test/test_queue.o



clean :
	${RM} stack.o test/test_stack test/test_stack.o queue.o test/test_queue test/test_queue.o