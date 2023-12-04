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

  unsigned int	lcm(unsigned int a, unsigned int b);
*/

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int n; //Used to iterate through potential common multiples

	if (a == 0 || b == 0) //If either a or b is equal to 0, it means at least one of the integers is zero, so the LCM is also 0
		  return (0);
	//Determine which of `a` or `b` is larger, and assign it to `n`, in order to start iterating from the larger number, optimizing the search for the LCM
	if (a > b)
		n = a;
	else
	   	n = b;
	while (1) //Create an infinite loop. Any non-zero value is considered true
	{
		if (n % a == 0 && n % b == 0) //Check if the current value of `n` is a multiple of both `a` and `b`, e.g. there are no remainders when dividing `n` both by a and b
			return (n);
		n++; //Repeat the process of checking if the incremented value of `n` is a common multiple, until it finds the smallest positive integer that is divisible by both `a` and `b`
	}
}

/*
#include <stdio.h>

int	 main(void)
{
		int	 x = -1;
		int	 y = 2932;

		printf("LCM of %d and %d is %d\n", x, y, lcm(x, y));
		return (0);
}*/