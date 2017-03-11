# include <stdio.h>
# include "list.h"

struct s_list *init_list(void)
{
  struct s_list *tmp = malloc(sizeof(struct s_list));
  tmp->tree = NULL;
  tmp->next = NULL;

  return tmp;
}

size_t size_list(struct s_list *list)
{
  struct s_list *tmp = list;
  size_t cpt = 0;
  for(;tmp != NULL; tmp = tmp->next)
    cpt += 1;

  return cpt;
}

void free_list(struct s_list *list)
{
  for(; list->next != NULL;){
    pop_list(list);
  }
  free(list);
}

void push_list(struct s_list *list, struct s_tree *val)
{
  struct s_list *tmp = malloc(sizeof(struct s_list));
  tmp->tree = val;
  tmp->next = list->next;
  list->next = tmp ;
}

struct s_tree *pop_list(struct s_list *list)
{
  struct s_list *pop = list->next;
  struct s_tree *tmp = pop->tree;
  list->next = pop->next;
  free(pop);
  return tmp;
}

void change_list(struct s_list *prev, struct s_list *next)
{
  struct s_tree *tmp =  pop_list(prev);
  push_list(next,tmp);
}
