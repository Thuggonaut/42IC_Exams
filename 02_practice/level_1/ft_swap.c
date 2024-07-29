/*
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);
*/
 
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

#include <stdio.h>

int main()
{
	int a = 42;
	int b = 24;

	ft_swap(&a, &b);
	printf("a = %d\nb = %d\n", a, b);
	return (0);
}