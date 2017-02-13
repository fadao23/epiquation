# include "parsing.h"
# include "test_tree.h"
# include <stdio.h>

int main()
{
  char *s = "pow(3 + y) + 56 * t + (5 - 9 /2 ) +34 = 5 - ln ( 4 *x + 6,3+5)";
	char *n = clean_string(s);
	printf("%s\n", n);
  tree_to_string(parse(n));

	return 0;
}
