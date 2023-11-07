/*
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)

  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);
*/

unsigned int	ft_hcf(unsigned int a, unsigned int b) //Define a function calculates the Highest Common Factor (HCF) or Greatest Common Divisor (GCD) of two numbers using the Euclidean algorithm
{
	unsigned int	temp;

	while (b != 0) //The Euclidean algorithm is used to find the HCF, which is the largest number that divides both a and b
	{
		//Calculate the remainder of a divided by b and swaps the values of a and b in each iteration until b becomes 0. At that point, a contains the HCF
		temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	hcf;

	if (a ==0 || b == 0) //If either a or b is equal to 0, it means at least one of the integers is zero, so the LCM is also 0
		return (0);
	hcf = ft_hcf(a, b);
	return ((a * b) / hcf);
}

/*
#include <stdio.h>

int	main(void)
{
	unsigned int	x = 12;
	unsigned int	y = 18;
	unsigned int	res = lcm(x, y);

	printf("LCM of %u and %u is %u\n", x, y, res);
	return (0);
}
*/