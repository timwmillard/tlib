CC=clang
RM=rm

all : tstack.o tqueue.o

tstack.o : tstack.c
	${CC} -o tstack.o -c tstack.c

tqueue.o : tqueue.c
	${CC} -o tqueue.o -c tqueue.c

test: test/test_tstack test/test_tqueue

test/test_tstack: test/test_tstack.o tstack.o
	${CC} -o test/test_tstack tstack.o test/test_tstack.o

test/test_tqueue: test/test_tqueue.o tqueue.o
	${CC} -o test/test_tqueue tqueue.o test/test_tqueue.o



clean :
	${RM} tstack.o test/test_tstack test/test_tstack.o tqueue.o test/test_tqueue test/test_tqueue.o