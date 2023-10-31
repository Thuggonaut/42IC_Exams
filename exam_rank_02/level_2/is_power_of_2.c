/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int		is_power_of_2(unsigned int n);
*/

int is_power_of_2(unsigned int n) //Define a function that takes in an unsigned integer (to ensure the input integer is always positive), and returns `1` (true) or `0` (false)
{
	if (n == 0)
		return (0); //Because `0` is not a power of `2`
	while (n % 2 == 0) //Loop as long as `n` is even, meaning it's divisible by `2` without a remainder
		n /= 2; //Divide `n` by `2`, checking if `n` is a power of `2` by repeatedly halving it. If `n` is a power of `2`, this division will eventually reduce it to `1`
	return (n == 1); //If `n` is equal to `1`, return `1` for true, otherwise return `0` for false, meaning `n` is not a power of `2`
}

/*
#1  We initialize `i` to `1` because it serves as a starting point for checking if `n` is a power of `2`.
		- By initializing `i` to `1`, we start at the lowest possible power of `2` (2^0 = 1). 
*/

/*
#include <stdio.h>

int main()
{
	unsigned int num;

	printf("Enter the number you want to test: ");
	scanf("%u", &num);
	if (is_power_of_2(num) == 1)
		printf("\n%u is a power of 2\n", num);
	else
		printf("\n%u is not a power of 2\n", num);
	return (0);
}
*/

