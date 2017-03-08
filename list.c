# include <stdio.h>
# include "list.h"

void queue_init(struct queue *queue)
{
  queue->store = malloc(sizeof(struct list));
  queue->store->tree = malloc(sizeof(struct s_tree));
  queue->sum = 0;
  queue->size = 0;
}
/*
 * queue_is_empty(queue) test for emptyness
*/
int queue_is_empty(struct queue *queue)
{

   return queue->size == 0;

}

/*
 * queue_push(queue, elm) push elm
*/
void queue_push(struct queue *queue, void *elm)
{
  struct list *tmp = malloc(sizeof (struct list));
  tmp->tree = malloc(sizeof(struct s_tree));
  tmp->tree->data = elm;

  if(!queue_is_empty(queue))
    {
      tmp->next = queue->store->next;
      queue->store->next = tmp;
    }
  else
  {
    tmp->next = tmp;
  }
  queue->size += 1;
  queue->store = tmp;
}

/*
 * queue_pop(queue) pop the next element (FIFO order)
 * returns NULL if the queue is empty
*/
void* queue_pop(struct queue *queue)
{
  if (!queue_is_empty(queue))
    {
      struct list *tmp = malloc(sizeof (struct list));
      tmp = queue->store->next;
      queue->store->next = tmp->next;
      queue->size -= 1;
      void *data = tmp->tree->data;
      free(tmp);
      return data;
    }
  else
    {
      return NULL;
    }


}
