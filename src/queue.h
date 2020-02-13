/*
 * queue.h
 * Defines a queue to mange TCB elements.
 */

#ifndef QUEUE_H
#define QUEUE_H


#include "tcb.h"

#include <unistd.h>


typedef struct queue QUEUE;


/* Create a new initialized QUEUE on the heap. Returns a pointer to
   the new block or NULL on error. */
QUEUE *queue_new(void);


/* Destroy queue, freeing all associated memory with it. It also frees
   all memory of the elements inside the queue. */
void queue_destroy(QUEUE *queue);


/* Return the number of items in queue. */
size_t queue_size(const QUEUE *queue);


/* Add elem to the end of queue. Returns 0 on succes and non-zero on
   failure.*/
int queue_enqueue(QUEUE *queue, TCB *elem);


/* Remove the first item from the queue and return it. The caller will
   have to free the reuturned element. Returns NULL if the queue is
   empty. */
TCB *queue_dequeue(QUEUE *queue);


/* Remove element with matching id from the queue. Returns the removed
   element or NULL if no such element exists. */
TCB *queue_remove_id(QUEUE *queue, int id);


#endif
