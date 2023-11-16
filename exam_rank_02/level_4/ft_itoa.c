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

int	len_digits(int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	if (n == 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = len_digits(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		*str = '-';
		nb *= -1;
	}
	if (nb == 0)
		*str = '0';
	while (nb)
	{
		*(str + len - 1) = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	return (str);
}

#include <stdio.h>

int	main(void)
{
	printf("Result of converted string: ''%s''\n", ft_itoa(-2147483648));
	return (0);
}