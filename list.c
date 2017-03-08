# include <stdio.h>
# include "list.h"

void queue_init(struct queue *queue)
{
  queue->store = malloc(sizeof(struct list));
  queue->store->tree = malloc(sizeof(struct s_tree));
  queue->sum = 0;
}

/*void queue_push(struct queue *queue, struct s_tree *elm)
{
  struct list *tmp = NULL;

  while(queue->store && queue->store->tree <= elm)
  {
    tmp = queue->store;
    queue->store = queue->store->next;
  }
   tmp->next = queue->store->next;
   queue->store->next = tmp;
}*/

void queue_push(struct queue *queue, void *elm)
{
  struct list *tmp = malloc(sizeof (struct list));
  tmp->tree = malloc(sizeof(struct s_tree));

  tmp->tree->data = elm;

  if(queue)
  {
    tmp->next = tmp;
  }
  else
  {
    tmp->next = queue->store->next;
    queue->store->next = tmp;
    //   tmp->next = tmp;
  }
  //queue->size += 1;
  queue->store = tmp;
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
