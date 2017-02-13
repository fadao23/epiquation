//List of function used to make list

# ifndef _EPIQUATION_LIST_H_
# define _EPIQUATION_LIST_H_

# include <stdlib.h>
# include "tree.h"

/* standard linked lists */
struct list {
  struct list   *next;
  struct s_tree *tree;
};

/*
 * queue container: replace sentinel and add abstraction
 */
struct queue {
  struct list *store;
  int         sum;
};

/*
 * queue_init(queue) initialize an empty queue container
 * allocation of the container is kept external for more flexibility
 */
void queue_init(struct queue *queue);

/*
 * queue_push(queue, elm) push elm
 */
void queue_push(struct queue *queue, struct s_tree *elm);

/*
 * queue_pop(queue) pop the next element (FIFO order)
 * returns NULL if the queue is empty
 */
struct s_tree *queue_pop(struct queue *queue);

# endif
