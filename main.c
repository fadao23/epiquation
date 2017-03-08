# include "parsing.h"
# include "test_tree.h"
# include "list.h"
# include "tree.h"
# include <stdio.h>
# include <err.h>
# include <assert.h>

/*void random(struct queue *test)
{
  struct queue *tmp = malloc(sizeof(struct queue));
  queue_init(tmp);
  int r = (rand() % 10);
  //int *p = &r;
  test->store->tree->data = &r;
}*/

void simple_test(size_t len)
{
  printf(">>> Simple Test: <<<\n");
  struct queue queue;
  queue_init(&queue);
  int *data = calloc(len, sizeof (int));
  if (!data)
    err(1, "allocating data failed, dying");
  printf("  Push:\n");
  for (size_t i = 0; i < len; ++i) {
    data[i] = (int)i;
    queue_push(&queue, data + i);
    printf("    pushed: %d\n", data[i]);
    assert(queue.size == i + 1);
  }
  printf("  after push, size: %zu\n", queue.size);
  assert(queue.size == len);
  while (!queue_is_empty(&queue)) {
    int *elm = queue_pop(&queue);
    assert(elm);
    printf("    pop: %d\n", *elm);
  }
  printf("  after pop, size: %zu\n", queue.size);
  assert(queue.size == 0);
  free(data);
}

int main(int argc, char *argv[])
{
  size_t len = 16;
  if (argc > 1)
    len = strtoul(argv[1], NULL, 10);
  simple_test(len);
  return 0;
}


/*int main(int argc, char * argv[])
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
}*/

