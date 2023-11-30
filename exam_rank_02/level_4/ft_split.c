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

int		is_delimiter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int		count_words(char *s)
{
	int		count = 0;
	int		flag = 0;

	while (*s)
	{
		if (is_delimiter(*s))
			flag = 0;
		else if (!flag)
		{
			flag = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	int		word_count = count_words(str);
	char	**result = (char **)malloc((word_count + 1) * sizeof(char *));

	if (!result)
		return (NULL);

	int i = 0;
	while (*str)
	{
		while (is_delimiter(*str))
			str++;
		if (*str == '\0')
			break ;

		char	*start = str;
		while (*str && !is_delimiter(*str))
			str++;

		int	 len = str - start;
		result[i] = (char *)malloc((len + 1) * sizeof(char));
		if (!result[i])
		{
			while (i > 0)
				free(result[--i]);
			free(result);
			return (NULL);
		}

		int	 j = 0;
		while (j < len)
		{
			result[i][j] = start[j];
			j++;
		}
		result[i][j] = '\0';
		i++;
	}
	result[i] = NULL;
	return (result);
}

#include <stdio.h>

int	 main(void)
{
	char	*s = "This is a sample string";
	char	**res = ft_split(s);

	if (!res)
	{
		printf("Error in ft_split function\n");
		return (1);
	}

	int	 i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}