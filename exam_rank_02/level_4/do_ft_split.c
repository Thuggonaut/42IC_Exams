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

char	**ft_split(char *str);
*/

#include <stdlib.h>

int	delimiter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int		wc(char *s)
{
	int	inword = 0;
	int	count = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t' && inword == 0)
		{
			inword = 1;
			count++;
		}
		else if (*s == ' ' || *s == '\t')
			inword = 0;
		s++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	int		wordcount = wc(str);
	char	**array = (char **)malloc((wordcount + 1) * sizeof(char *));
	int		i = 0;

	if (!array)
		return (NULL);

	while (*str)
	{
		//Skip leading whitespace
		while (delimiter(*str))
			str++;
		//Break if end of string
		if (*str == '\0')
			break ;
		//Account for the start of a word
		char *start = str;
		//Find the word length
		while (!delimiter(*str) && *str)
			str++;
		int len = str - start;
		//Allocate memory in array
		array[i] = (char *)malloc((len + 1) * sizeof(char));
		//Copy the current word from start to result[i]
		int word = 0;
		while (word < len)
		{
			array[i][word] = start[word];
			word++;
		}
		//Null terminate and move to next word/array
		array[i][word] = '\0';
		i++;
	}
	array[i] = NULL;
	return (array);
}

/*
#include <stdio.h>

int	main(void)
{
	char *s = "this is a test string";
	char **array = ft_split(s);
	int i = 0;
	int count = wc(s);

	printf("wordcount: %d\n", count);
	while (i < count)
	{
		printf("%s\n", array[i]);
		i++;
	}
	return (0);
}
*/