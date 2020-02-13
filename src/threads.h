/*
 * threads.h
 * Interface to a barebones user level thread library.
 */

#ifndef THREADS_H
#define THREADS_H


/* Create a new thread. func is the function that will be run once the
   thread starts execution and arg is the argument for that
   function. On success, returns an id equal or greater to 0. On
   failure, errno is set and -1 is returned. */
int threads_create(void *(*start_routine) (void *), void *arg);


/* Stop execution of the thread calling this function. */
void threads_exit(void *result);


/* Wait for the thread with matching id to finish execution, that is,
   for it to call threads_exit. On success, the threads result is
   written into result and id is returned. If no completed thread with
   matching id exists, 0 is returned. On error, -1 is returned and
   errno is set. */
int threads_join(int id, void **result);


#endif
