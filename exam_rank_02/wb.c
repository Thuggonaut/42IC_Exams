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

int		ft_atoi(char *s)
{
	int		res = 0;
	int		sign = 1;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			res = (res * 10) + *s;
		s++;
	}
	return (res * sign);
}

void	put_nbr(int n)
{
	char	digit;

	if (n > 9)
		put_nbr(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int		is_prime(int n)
{
	int		i = 2;

	if (i <= 1)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void 	add_prime_sum(int n)
{
	int 	res = n;
	int		sum = 0;
	int		i = 2;

	while (i <= res)
	{
		if ((is_prime(i)))
			sum += 1;
		i++;
	}
	put_nbr(sum);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && ft_atoi(argv[1]) > 1)
		add_prime_sum(ft_atoi(argv[1]));
	else
		put_nbr(0);
	write(1, "\n", 1);
	return (0);
}