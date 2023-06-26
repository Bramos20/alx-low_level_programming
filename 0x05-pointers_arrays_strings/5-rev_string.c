#include <stdio.h>

void rev_string(char *s)
{
	if (s == NULL)
        return;

	int l = 0;
	char *e = s;
	char *n;

	while (*e != '\0')
	{
		l++;
		e++;
	}
	e--;

	for (*n = s; n < e; n++, e--)
	{
		char t = *n;
		*n = *e;
		*e = t;
	}
}
