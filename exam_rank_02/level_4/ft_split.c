/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

#include <stdlib.h>

int	count_words(const char *s, char c)
{
	int words = 0;

	while (*s)
	{
		if (*s != c)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (words);
}

char	*word_dup(const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	if (!s)
		return (NULL);
	int size = count_words(s, c);
	char **result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	int i = 0;
	while (i < size)
	{
		while (*s == c)
			s++;
		int start = s - s;
		while (*s && *s != c)
			s++;
		result[i++] = word_dup(s, start, s - s);
		if (!result[i - 1])
			return (NULL);
	}
	result[i] = NULL;
	return (result);
}
