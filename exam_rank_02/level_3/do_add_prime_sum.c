/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h> //To call the write() function
#include <stdlib.h> //To call the exit() function

int ft_atoi(char *s) //Define a function that takes a string representation of a number and return an integer (the actual number)
{
	int	res; //Declare an integer variable to store the converted result from string to integer
	int	sign; //To check for a negative number

	res = 0; //Initialized to `0` because no conversion has occured yet
	sign = 1;
	if (*s == '-') //Check for a negative sign at the start of the string
	{
		sign = -1; //Set to negative
		s++; //Move to the next character
	}
	while (*s) //Loop until the end of the string is reached
		res = res * 10 + *s++ - '0'; //For the current character in `s`, multiply `res` by `10`, then add the ASCII value of the current character (subtracting `48` to get the actual digit), then assign the result to res. See #1
	return (res * sign); //Return the actual digit of the string representation of an integer
}

void	ft_putnbr(int n) //Define a function that takes an integer. The return type is `void` because the function will print the character `res` to the STDOUT
{
	char digit; //Declare a character variable to store the converted result from integer to character representation of that integer
		
	if (n > 9) //Checks if `n` consists of more than `1` digit
		ft_putnbr(n / 10); //If so, it calls itself recursively with `n / 10`, effectively removing the last digit of `n`, then passing the remaining digits to the next recursive call
	digit = (n % 10) + '0'; //Calculates the remainder of `n / 10`, effectively giving us the last digit of `n`, then add the ASCII value of `0`, effectively giving us the character representation of the digit, before assigning it to `res`
	write(1, &digit, 1); //Writes the character to the STDOUT
}

int is_prime(int n) //Declare a function that takes an integer, checks if it is prime, and returns an integer that determines whether `n` is prime
{
	int i; //Declare an integer variable to be used as a counter in the loop that checks for factors (not a prime) of `n`

	if (n <= 1) //Checks for input numbers less than or equal to `1`
		return (0); //If so, return `0` for `false` as `1` or less is not a prime number
	i = 2; //Initialised to `2` because all numbers are divisible by `1` and themselves. If we started from `1` or the number itself, it would always result in finding a divisor and incorrectly identifying the number as non-prime. For a number to be prime, it must have no other divisors apart from 1 and itself
	while (i * i <= n) //Checks for potential factors of `n`. Squaring `i` and checking it against `n` prevents unnecessary iterations for larger numbers, it is equivalent to checking up to the square root of `n`. Any factors of a number `n` must be less than or equal to the square root of `n`
	{
		if (n % i == 0) //Checks if `n` is divisible by `i` (i.e., `i` is a factor of `n`).
			return (0); //If so, then `n` is not prime, return `0` for `false`
		i++; //Move to the next number to check for the next potential factor
	}
	return (1); //If `n` is not less than or `1`, and if `n` can not be divided evenly by any number from `2` up to the square root of `n`, then `n` is prime. Return `1` for `true`
}

void add_prime_sum(int n) //Define a function that takes a string and prints to the STDOUT the `sum` of all prime numbers inferior or equal to a number represented by `char `str`
{
	int sum; //Declare an integer variable to store the accumulated sum of the prime numbers
	int i; //Declare an integer variable to be used as a counter in a loop

	sum = 0; //Initialise to `0` to prepare `sum` for its accumulation of prime numbers
	i = 2; //Initialised to `2` because the smallest prime number is `2`
	
	while (i <= n) //Loop from `2` until `n`
	{
		if (is_prime(i)) //Checks if `i` is prime
			sum += i; //If so, add `i`'s value to `sum`
		i++; //Move to the next number between `2` and `n` to check for potential primes before adding it's value to `sum`
	}
	ft_putnbr(sum); //Write the accumulated `sum` to the STDOUT
}

int main(int argc, char **argv) //`argv` is a pointer to an array of strings. By using a double pointer `char **argv`, the program can access and retrieve each individual argument as a null-terminated string
{
	if (argc == 2 && ft_atoi(argv[1]) > 1)
		add_prime_sum(ft_atoi(argv[1]));
	else
		ft_putnbr(0);
	write (1, "\n", 1);
	return (0);
}


/*
PRIME NUMBERS:

1.  A prime number is a natural number greater than `1` that has no positive divisors other than `1` and itself. 
	- In other words, a prime number is a number that cannot be formed by multiplying two smaller natural numbers. 
	- The opposite of `prime` is `composite`.
	- The first few prime numbers are `2`, `3`, `5`, `7`, `11`, and `13`.
	- https://www.youtube.com/watch?v=klcIklsWzrY 


SIEVE OF ERATOSTHENES ALGORITHM:

1.  An algorithm used to find all prime numbers up to a given limit. It is one of the most efficient ways to find small prime numbers. 

2.  To implement the Sieve of Eratosthenes algorithm in C, you can follow these steps:

	a. Declare an array of size `num-1` to store the numbers from `2` to `num`. 
			- Initialize all elements of the array with their respective numbers using a while loop.

	b. Use a while loop to iterate through the array and cross out the non-prime numbers. 
			- Start with the first prime number, which is `2`, and mark all its multiples as `0`. 
			- Move on to the next number that is not crossed out, which is a prime, and repeat the process.

	c. Print only the prime numbers from the array using a while loop.

	d. Here's an example implementation:

#include <stdio.h>
#include <math.h>


void sieveOfEratosthenes(int num) 
{
	int sieve[num-1];
	int index = 0;
	int fillnum = 2;

	while (fillnum <= num) 
	{
		sieve[index] = fillnum;
		index++;
		fillnum++;
	}

	int primenums = 0;
	while (primenums < sqrt(num)) 
	{
		if (sieve[primenums] != 0) 
		{
			int multiple = sieve[primenums];
		
			while (multiple < num) 
			{
				if (sieve[multiple] != 0) 
				{
					sieve[multiple] = 0;
				}
				multiple += sieve[primenums];
			}
		}
		primenums++;
	}

	int k = 0;
	while (k < num-1) 
	{
		if (sieve[k] != 0) 
		{
			printf("%d ", sieve[k]);
		}
		k++;
	}
}

int main() 
{
	int num = 1000;
	sieveOfEratosthenes(num);
	return 0;
}

#1  Re ft_atoi(), Let's break down the line `res = res * 10 + *s++ - 48;`, which is executed until the end of `s` is reached:
	a.  `res * 10`:
		- The current value of res is multiplied by 10. This is done because each digit in a number is ten times more significant than the digit to its right. 
		- So, to make space for the next digit, we multiply res by 10.
	b. `*s++`: 
		- This is a bit trickier. It's using pointer arithmetic and the post-increment operator. 
		- The `*s` part is dereferencing the pointer, getting the character that `s` currently points to. 
		- The `++` part increments the pointer `s` to the next character in the string after the value is fetched. 
		- So this whole expression fetches the current character in the string and then moves the pointer to the next character.
	c.  `- 48`: 
		- The characters '0' through '9' in ASCII are represented by the numbers `48` through `57`, so subtracting `48` from an ASCII character yields the 
		  integer value of a number character. 
		- This is done to convert the character digit to its actual integer value.
	d.  Example if *s = 123:
		- Initially, res = 0.
		- We fetch the first char, which is '1', its ASCII value minus `48` is `1`. So `res = res * 10 + 1` --> `res` is now `1`.
		- We fetch the second char, which is '2'. So `res = res * 10 + 2` --> `res` is now `12`.
		- We fetch the third char, which is '3'. So `res = res * 10 + 3` --> `res` is now `123`.
		- After the last digit, there are no more characters, so we stop there and `res` is the integer equivalent of the string.


#2	
If `i` is greater than the square root of `n`, checking for further values of `i` becomes redundant because any potential divisor must have already been 
found in previous iterations. This significantly reduces the number of unnecessary iterations, making the primality check more efficient.
*/
