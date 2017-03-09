# include <stdio.h>
# include "list.h"

struct list *init_list(void);
{
  struct list *tmp = malloc(sizeof(struct list));
  tmp->tree = malloc(sizeof(struct s_tree));
  tmp->next = NULL;

  return tmp;
}


void free_list(struct list *list)
{
  free(list->tree);
  free(list);
}

/*
 * queue_is_empty(queue) test for emptyness
*/
int queue_is_empty(struct queue *queue)
{

   return queue->size == 0;

}

/*
**  list_add: add a val in list
**    l: list to push in
**    val: the node to push
**  list_add add [val] after the sentinelle of [l]
*/
void push_list(struct list *list, struct s_tree *val)
{
  struct list *tmp = malloc(sizeof(struct list));
  tmp->tree = malloc(sizeof(struct s_tree));
  tmp->tree = val;

  if(list)
  {
    tmp->next = list->next;
    list->next = tmp ;
  }
  else{
    list->next = tmp;
    tmp->next = NULL;
  }
}

struct s_tree *pop_list(struct list *list)
{
  struct s_tree *tmp = init_list();
  struct list *pop = malloc(sizeof(struct list));

  tmp = list->tree;
  pop->next = list->next;
  list->next = pop->next;

  return tmp;
}

/*
**  change_list: pop an element from list and push this in another
**    prev: the list to push from
**    next: the list to push in
**  change_list pop the next element in [prev] and push in the next element of
**  [next]
*/
void change_list(struct list *prev, struct list *next)
{
  struct list *tmp = init_list();
  tmp->next->tree = pop_list(list);
  push_list(next,tmp->next->tree);
  free(tmp);
}
