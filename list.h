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

struct list *init_list(void);

/*                                                                              
**  list_add: add a val in list                                                 
**    l: list to push in                                                        
**    val: the node to push                                                     
**  list_add add [val] after the sentinelle of [l]                              
*/                                                                              
void push_list(struct list *list, struct s_tree *val);                              

struct s_tree *pop_list(struct list *list);

/*                                                                              
**  change_list: pop an element from list and push this in another              
**    prev: the list to push from                                               
**    next: the list to push in                                                 
**  change_list pop the next element in [prev] and push in the next element of  
**  [next]                                                                      
*/                                                                              
void change_list(struct list *prev, struct list *next);                         

void free_list(struct list *list);

# endif
