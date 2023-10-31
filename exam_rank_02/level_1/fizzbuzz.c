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

void	write_nbr(int n) //Define a function that takes an integer, and print the integer digit by digit. Type void because it performs an operation and does not return a value.
{
	int	nbr;

	if (n > 9) //If there are more than one digit to be printed
		write_nbr(n / 10); //Recursively calls itself, with `n / 10`, effectively removing the last digit of `n`. This means, the function "descends" through the digits, printing the remaining digits before printing the last digit. 
	nbr = (n % 10) + '0'; //Update the value, which is the last digit of `n` (the remainder of n % 10), converted to its ASCII character, by adding 48
	write(1, &nbr, 1); 
}

int main(void)
{
	int i;

	i = 1;
	while (i <= 100) //This while loop iterates from `i = 1` to `i = 100`
	{
		if (i % 3 == 0 && i % 5 == 0) //Check if `i` is divisible by both 3 and 5
			write(1, "fizzbuzz", 8); //If so, print the string "fizzbuzz" to the standard output
		else if (i % 3 == 0) //Check if `i` is divisible by `3`
			write(1, "fizz", 4);
		else if (i % 5 == 0) //Check if `i` is divisible by `5`
			write(1, "buzz", 4);
		else  
			write_nbr(i); //If no if conditions are met, print the number
		i++; //Move to the next number for processing
		write(1, "\n", 1);
	}
	return (0);
}
