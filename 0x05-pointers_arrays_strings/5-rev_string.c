#include <stdio.h>

void rev_string(char *s)
{
	if (s == NULL)
        return;

	int l = 0;
	char *e = s;

	while (*e != '\0')
	{
		l++;
		e++;
	}
	e--;

	for (char *n = s; n < e; n++, e--)
	{
		char t = *n;
		*n = *e;
		*e = t;
	}
}
