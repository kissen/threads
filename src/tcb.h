/*
 * tcb.h
 * Defines the TCB (thread control block) data structure and functions
 * to work with it.
 */

#ifndef TCB_H
#define TCB_H


#include <stdbool.h>
#include <stdint.h>
#include <ucontext.h>


typedef struct {
    int id;
    ucontext_t context;
    bool has_dynamic_stack;
    void *(*start_routine) (void *);
    void *argument;
    void *return_value;
} TCB;


/* Create a new zeroed TCB on the heap. Returns a pointer to the new
   block or NULL on error. */
TCB *tcb_new(void);


/* Destroy block, freeing all associated memory with it */
void tcb_destroy(TCB *block);


#endif
