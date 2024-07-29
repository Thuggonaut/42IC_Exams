/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/ 

#include <stdlib.h>

int lendidigit(int n) {
	int len = 0;

	if (n == 0)
		len++;
	if (n < 0) {
		len++;
		n *= -1;
	}
		
	while (n) {
		n /= 10;
		len++;
	}
	return (len);
}

char *ft_itoa(int nbr) {
	int len = lendidigit(nbr);
	char *res = (char *)malloc((len + 1) * sizeof(char));

	res[len] = '\0';

	if (nbr < 0) {
		nbr *= -1;
		*res = '-';
	}
	if (nbr == 0)
		*res = '0';
	while (nbr) {
		res[len - 1] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (res);
}

#include <stdio.h>

int main() {
	int a = 42;
	char *s = ft_itoa(a);

	printf("%s\n", s);
	return (0);
}