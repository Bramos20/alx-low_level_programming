#include <stdio.h>

void rev_string(char *s)
{
	int l;
	char *e;

	if (s == NULL)
		return;

	l = 0;
	e = s;

	while (*e != '\0')
	{
		l++;
		e++;
	}
	e--;
	
	char *n;
	for (n = s; n < e; n++, e--)
	{
		char t = *n;
		*n = *e;
		*e = t;
	}
}
