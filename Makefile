CC=clang
RM=rm

all : tstack.o

tstack.o : tstack.c
	${CC} -o tstack.o -c tstack.c

test: test/test_tstack

test/test_tstack: test/test_tstack.o
	${CC} -o test/test_tstack tstack.o test/test_tstack.o

test_stack.o: test/test_stack.c
	${CC} -o test_tstack.o -c test_tstack.c

clean :
	${RM} tstack.o test/test_tstack test/test_tstack.o