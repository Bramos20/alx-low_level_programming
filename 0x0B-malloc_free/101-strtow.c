#include "main.h"
#include <stdlib.h>
#include <string.h>

char **strtow(char *str)
{
	if (str == NULL || *str == '\0')
		return NULL;

	int word_count = 0;
	char *ptr = str;
	int in_word = 0;
	while (*ptr != '\0')
	{
		if (*ptr == ' ')
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			word_count++;
		}
		ptr++;
	}

	char **words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return NULL;
	words[word_count] = NULL;

	int i = 0;
	char *word_start = str;
	in_word = 0;
	while (*str != '\0')
	{
		if (*str == ' ')
		{
			if (in_word)
			{
				int word_len = str - word_start;
				words[i] = (char *)malloc((word_len + 1) * sizeof(char));
				if (words[i] == NULL)
				{
					for (int j = 0; j < i; j++)
						free(words[j]);
					free(words);
					return NULL;
				}
				strncpy(words[i], word_start, word_len);
				words[i][word_len] = '\0';
				i++;
				in_word = 0;
			}
		}
		else if (in_word == 0)
		{
			in_word = 1;
			word_start = str;
		}
		str++;
	}

	if (in_word)
	{
		int word_len = str - word_start;
		words[i] = (char *)malloc((word_len + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			for (int j = 0; j <= i; j++)
				free(words[j]);
			free(words);
			return NULL;
		}
		strncpy(words[i], word_start, word_len);
		words[i][word_len] = '\0';
		i++;
	}

	return words;
}

