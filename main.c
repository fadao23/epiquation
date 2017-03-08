# include "parsing.h"
# include "test_tree.h"
# include "list.h"
# include "tree.h"
# include <stdio.h>
# include <err.h>

void random(struct queue *test)
{
  struct queue *tmp = malloc(sizeof(struct queue));
  queue_init(tmp);
  int r = (rand() % 10);
  //int *p = &r;
  test->store->tree->data = &r;
}


int main(int argc, char * argv[])
{
  if (argc < 1)
    err(1, "Miising argument");

  size_t nb = atoi(argv[1]);
  printf("Nombre d'elm %zu\n",nb);
  struct queue *test = malloc(nb*sizeof(struct queue));
  int print = 0, print1 = 0;

  int value = 10;
  void *t = &value;

  for (size_t i = 0; i < nb; i++)
  {
    queue_init(test+i);
    random(test+i);
    print = *(int*)(test+i)->store->tree->data;
    printf("%zu |",print+i);
  }
   printf("\n");
   queue_push(test,t);

  for (size_t i = 0; i < nb; i++)
  {
    print1 = *(int*)(test+i)->store->tree->data;
    printf("%zu |",print1+i);
  }
   printf("\n");
  return 0;
}
