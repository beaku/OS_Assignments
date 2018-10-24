#include <stdio.h>
#include <stdlib.h>
#include "threads.h"

static struct thread *current_thread = NULL;
static struct thread *previous_thread = NULL;
static int next_thread_id = 0;

struct thread *thread_create(void (*f)(void *), void *arg) {
	struct thread *t =(struct thread *) malloc(sizeof(struct thread));
    int i;
    for(i=0;i<10;i++)
        t->stack[i]=0;
//	t->base_pointer = t->stack + 10;
	
	t->func = f;
	t->arg = arg;
	t->thread_id = next_thread_id++;
	return t;
}


void thread_add_runqueue(struct thread *t) {
	if (current_thread == NULL)
	{
       current_thread = t;
	   current_thread->next_thread = t;
	} 
    else 
    {
		t->next_thread = current_thread->next_thread;
		current_thread->next_thread = t;
	}
}

void thread_yield(void) {
	schedule();
	dispatch();
}

void schedule(void) {
	previous_thread = current_thread;
	current_thread = current_thread->next_thread;
}