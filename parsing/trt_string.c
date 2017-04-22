# include "parsing.h"

float get_float(const char *string) {
  float res;
  sscanf(string, "%f", &res);
  return res;
}

char *clean_string(char *string)
{
	int lgt = strlen(string) + 1, cpt = 0, i;
	char *new_s = calloc(lgt, sizeof (char));
	for (i = 0; i < lgt; ++i)
	{
		char c = *(string + i);
		if (c >= 'A' && c <= 'Z')
			*(new_s + cpt++) = c + 32;
		else if ((c >= '(' && c <= '9') || (c >= 'a' && c <= 'z') || c == '=')
			*(new_s + cpt++) = c;
	}
	return new_s;
}

int comp_regex(char *string, char *reg)
{
 	regex_t regex;
	int 		err_reg = 0;
	err_reg = regcomp(&regex, reg, REG_NOSUB | REG_EXTENDED | REG_NEWLINE);
	if (err_reg)
  {
  char *test = calloc(100,sizeof(char));
  regerror(err_reg,&regex,test,100);
  printf("%s\n",reg);
  printf("%s\n",test);
  err(1, "Error initialising function regex");
	}
  err_reg = regexec(&regex, string, 0, NULL, 0);
  regfree(&regex);
	if (!err_reg)
		return 1;
	else if (err_reg == REG_NOMATCH)
		return 0;
	else
		err(1, "Error executing function regex");
}
