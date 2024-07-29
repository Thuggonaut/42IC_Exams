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

//1. wc()
//2. malloc **array, check NULL
//3. while loop
//4. skip ws, then if eos, break
//5. *start pointer to start of word
//6. find word len, while !ws, s++, len = s - start
//7. malloc word in array
//8. copy word, int i, int j; array[i][j] = start[j]
//9. null term word and array

#include <stdlib.h>
#include <stdbool.h>

bool ws(char c) {
	return (c == ' ' || (c >= 9 && c <= 13));
}

int wc(char *s) {
	int count = 0;

	while (ws(*s))
			s++;
	while (*s) {
		if (!ws(*s) && ws(*(s - 1)))
			count++;
		s++;
	}
	return (count);
}

char	**ft_split(char *str) {
	int len = wc(str);
	char **array = (char **)malloc((len + 1) * sizeof(char *));
	char *start;
	int wlen;
	int i = 0;

	while (*str) {
		while (ws(*str)) {
			str++;
		}
		if (!*str)
			break;
		start = str;
		while (!ws(*str) && *str)
			str++;
		wlen = str - start;
		array[i] = (char *)malloc((wlen + 1) * sizeof(char));
		
		int word = 0;
		while (word < wlen) {
			array[i][word] = start[word];
			word++;
		}
		array[i][word] = '\0';
		i++;
	}
	array[i] = NULL;
	return (array);
}

#include <stdio.h>

int     main()
{
        char    *s = "There     should be an array of 8         words! ";
        char    **res = ft_split(s);
        int     count = wc(s);
        int     i = 0;

        while (i < count)
        {
                printf("%s\n", res[i]);
                i++;
        }
		printf("word count: %d\n", count);
        return (0);
}