# include <stdio.h>
# include "list.h"

struct list *init_list(void)
{
  struct list *tmp = malloc(sizeof(struct list));
  tmp->tree = NULL;
  tmp->next = NULL;

  return tmp;
}


void free_list(struct list *list)
{
  for(; list->next != NULL;){
    pop_list(list);
  }
  free(list);
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
  tmp->tree = val;
  tmp->next = list->next;
  list->next = tmp ;
}

struct s_tree *pop_list(struct list *list)
{
  struct list *pop = list->next;
  struct s_tree *tmp = pop->tree;
  list->next = pop->next;
  free(pop);
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
  struct s_tree *tmp =  pop_list(prev);
  push_list(next,tmp);
}
