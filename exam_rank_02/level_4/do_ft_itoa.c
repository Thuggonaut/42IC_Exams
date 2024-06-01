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

#include <stdlib.h> //To call malloc()

int	len_digits(int n) //Define a function that returns the length of an integer
{
	int		len; //To store the length count

	len = 0;
	if (n < 0) //Account for negative numbers
	{
		len++; //The `-` sign will need to be allocated for in memory
		n *= -1; //`n` must be negated in order to later extract each digit from `n`
	}
	if (n == 0) //Account for if `0`
		len++; //Which will need to be allocated for memory
	while (n) //Loop until n reaches `0`, e.g., when a single digit e.g. `0 - 9` is divided by `10`, it will be `0`
	{
		n /= 10; //This essentially takes of one rightmost digit at a time
		len++; //Each time tracking the length count
	}
	return (len);
}

char	*ft_itoa(int nbr) //Define a function that will convert an integer into its represented string
{
	char	*s; //To store the converted result
	int		len; //Length needed for memory allocation
	long	n; //Account for larger data types than `int`

	n = nbr; 
	len = len_digits(nbr);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s) //Always check if allocation successfull
		return (NULL);
	s[len] = '\0'; //If successful, null terminate our string. Note, we will be assigning our char array backwards, from the rightmist digit to the leftmost
	if (n < 0) //Account for negative numbers
	{
		*s = '-'; //If so, assign the first character of the string the `-` sign
		n *= -1; //`n` must be negated in order to process individual digits later
	}
	if (n == 0) //Account for if `n` is `0`
		*s = '0';
	while (n)  //Loop until n reaches `0`, e.g., when a single digit e.g. `0 - 9` is divided by `10`, it will be `0`
	{
		*(s + len - 1) = n % 10 + '0'; //From the rightmost digit, assign to our array, the remainder which is the last digit of the number
		n /= 10; //Takes of the last digit, to process the next digit from the right
		len--; //Decrement as we assign our char array characters backwards
	}
	return (s);
}

/*
TEST 2ND ATTEMPT: also works

char	*ft_itoa(int nbr)
{
	int		len = len_digits(nbr);
	char	*res = (char *)malloc((len + 1) * sizeof (char));
	char	*temp = res;
	if (nbr < 0)
	{
		*temp = '-';
		nbr *= -1;
		temp++;
	}	
	temp[len] = '\0';
	while (nbr > 9)
	{
		len--;
		temp[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	len--;
	temp[len] = nbr + '0';
	return (res);
}
*/

/*
int	main(void)
{
	int 	n = -123;
	char	*value = ft_itoa(n);

	printf("Conversion successful if %s is the same as %d\n", value, n);
	return (0);
}
*/