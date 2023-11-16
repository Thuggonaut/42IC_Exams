/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>
*/

#include <unistd.h> //To call write()

void	ft_putnbr(int n) //Define a function that takes an integer, and print the integer digit by digit. Type void because it performs an operation and does not return a value.
{
	int	digit;

	if (n > 9) //If there are more than one digit to be printed
		ft_putnbr(n / 10); //Recursively calls itself, with `n / 10`, effectively removing the last digit of `n`. This means, the function "descends" through the digits, printing the remaining digits before printing the rightmost digit. 
	digit = (n % 10) + '0'; //Update the value, which is the leftmost digit of `n` (the remainder of n % 10), converted to its ASCII character, by adding 48
	write(1, &digit, 1); 
}

void	fizzbuzz(void)
{
	int n;

	n = 0;
	while (n++ < 100) //This while loop iterates from `n = 1` to `n = 100`
	{
		if (n % 3 == 0 && n % 5 == 0) //Check if `n` is divisible by both 3 and 5. NOTE: THIS CONDITION MUST BE CHECKED FIRST, ELSE THE OTHER TWO CONDITIONS WILL BE MET FIRST
			write(1, "fizzbuzz", 8); //If so, print the string "fizzbuzz" to the standard output
		else if (n % 3 == 0) //Check if `n` is divisible by `3`
			write(1, "fizz", 4);
		else if (n % 5 == 0) //Check if `n` is divisible by `5`
			write(1, "buzz", 4);
		else  
			ft_putnbr(n); //If no if conditions are met, print the number
		write(1, "\n", 1);
	}
}

int	main(void)
{
	fizzbuzz();
	return (0);
}