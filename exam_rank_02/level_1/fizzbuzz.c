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

void    ft_write_number(int n) //Define a function that takes an integer, and print the integer digit by digit. Type void because it performs an operation and does not return a value.
{
    char s[10]; //Declare a character array

    s[10] = "0123456789"; //The array is initialised with digits '0' to '9', each chracter representing the corresponding digit
    if (n > 9) //If there are more than one digit to be printed
        ft_write_number(n / 10); //Recursively calls itself, with `n / 10`, effectively removing the last digit of `n`. This means, the function "descends" through the digits, printing the remaining digits before printing the last digit. 
    write(1, &s[n % 10], 1); //&s[n % 10] takes the address of the character at index [n % 10]. `n % 10` calculates the remainder, representing the last digit of `n`. When the base case is reached, it starts returning from the recursive calls and printing `n` from left to right.
}

int main()
{
    int i;

    i = 0;
    while (i <= 100) //This while loop iterates from `i = 1` to `i = 100`
    {
		if (i % 15 == 0) //Checks if `i` is divisible by `15` (divisible by both 3 and 5)the string "fizzbuzz" to the standard output
			write(1, "fizzbuzz", 8); //prints the string "fizzbuzz" to the standard output
		else if (i % 3 == 0) //Checks if `i` is divisible by `3`
			write(1, "fizz", 4);
		else if (i % 5 == 0) //Checks if `i` is divisible by `5`
			write(1, "buzz", 4);
		else  
			ft_write_number(i); //If no if conditions are met, ft_write_number() passes the current value of `i` and prints the number digit by digit
		i++; //Move to the next number for processing
		write(1, "\n", 1);
    }
    return (0);
}
