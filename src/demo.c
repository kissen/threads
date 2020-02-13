#include "threads.h"

#include <stdio.h>
#include <stdlib.h>


/*
static void *magic = NULL;
static unsigned count;


static void *thread0(void *arg)
{
    for (;;) {
	if (magic != arg) {
	    printf("Hello, this is thread %lu with count %u.\n", (unsigned long) arg, count);
	    magic = arg;

	    count += 1;
	}
    }

    return NULL;
}
*/

static void *thread1(void *arg)
{
    if ((unsigned long) arg % 2 == 0) {
	return arg;
    } else {
	for (;;) {
	}
    }
}


int main(void)
{
    puts("Hello, this is main().");

    /*

    for (unsigned long i = 0; i < 8; ++i) {
	void *arg = (void *) i;

	if (threads_create(thread0, arg) == -1) {
	    perror("threads_create");
	    exit(EXIT_FAILURE);
	}
    }

    for (;;) {
	if (magic != 0x0) {
	    puts("Hello, this is main().");
	    magic = 0x0;
	}
    }
    
    */

    int threads[8];

    for (unsigned long i = 0; i < 8; ++i) {
	void *arg = (void *) i;

	if ((threads[i] = threads_create(thread1, arg)) == -1) {
	    perror("threads_create");
	    exit(EXIT_FAILURE);
	}
    }

    for (int i = 0; i < 8; ++i) {
	int id = threads[i];

	while (1) {
	    void *res;

	    if (threads_join(id, &res) > 0) {
		printf("joined thread %d with result %p\n", id, res);
		break;
	    }
	}
    }
}
