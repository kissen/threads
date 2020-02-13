#include "tcb.h"

#include <stdlib.h>


TCB *tcb_new(void)
{
    static int next_id = 1;

    TCB *new;

    if ((new = calloc(1, sizeof(TCB))) == NULL) {
	return NULL;
    }

    new->id = next_id++;
    return new;
}


void tcb_destroy(TCB *block)
{
    if (block->has_dynamic_stack) {
	free(block->context.uc_stack.ss_sp);
    }

    free(block);
}
