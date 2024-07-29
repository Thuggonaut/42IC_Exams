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

#include <unistd.h>

void putn(int n) {
	int digit;

	if (n > 9)
		putn(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int ft_atoi(char *s) {
	int res = 0;

	while(*s) {
		res = (res * 10) + *s++ - '0';
	}
	return (res);
}

int is_prime(int n) {
	int i = 2;

	while (i * i <= n) {
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void ft(int n) {
	int i = 2;
	int sum = 0;

	while (i <= n) {
		if (is_prime(i))
			sum += i;
		i++;
	}
	putn(sum);
}

int main(int ac, char **av) {
	if (ac == 2 && ft_atoi(av[1]) > 1)
		ft(ft_atoi(av[1]));
	else
		putn(0);
	write(1, "\n", 1);
	return (0);
}