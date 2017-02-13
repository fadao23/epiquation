# include <stdio.h>
# include "list.h"

void queue_init(struct queue *queue)
{
  queue->store = NULL;
  queue->sum = 0;
}

void queue_push(struct queue *queue, struct s_tree *elm)
{
  struct list *tmp = NULL;

  while(queue->store && queue->store->tree <= elm)
  {
    tmp = queue->store;
    queue->store = queue->store->next;
  }
   tmp->next = queue->store->next;
   queue->store->next = tmp;
}


struct s_tree *queue_pop(struct queue *queue)
{
  if(queue != NULL)
  {
    struct list *tmp = malloc(sizeof(struct list));
    tmp = queue->store->next;
    queue->store->next = tmp->next;
    struct s_tree *test = tmp->tree;
    free(tmp);
    return test;
  }
  else
    return NULL;
}
