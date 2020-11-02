CC=clang
RM=rm
MKDIR=mkdir

TESTBINDIR = test/bin

all : stack.o queue.o

stack.o : stack.c
	${CC} -o stack.o -c stack.c

queue.o : queue.c
	${CC} -o queue.o -c queue.c

test: test/test_stack test/test_queue testbindir

test/test_stack: test/test_stack.o stack.o
	${CC} -o $(TESTBINDIR)/test_stack stack.o test/test_stack.o

test/test_queue: test/test_queue.o queue.o
	${CC} -o $(TESTBINDIR)/test_queue queue.o test/test_queue.o


testbindir: | $(TESTBINDIR)

$(TESTBINDIR):
	$(MKDIR) -p $(TESTBINDIR)

clean :
	${RM} stack.o $(TESTBINDIR)/test_stack test/test_stack.o queue.o $(TESTBINDIR)/test_queue test/test_queue.o