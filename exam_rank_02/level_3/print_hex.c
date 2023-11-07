/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>

int ft_isdigit(int c) //Define a function that takes a character that checks if the given character is a digit
{
    if (c >= '0' && c <= '9') //Check if the character is a digit 0-9
        return (1); //Returns 1 because it represents a true value in C. By convention, 0 is considered false, and any non-zero value is considered true (indicates that the character is a digit)
	return (0); //When the function returns 0, it indicates that the character is not a digit (false)
}

int	ft_atoi(const char *s) //Define a function that takes a string representation of an integer, and converts it into an actual integer value. `const char *` type because we are not modifying the content of the string
{
	int			res; //To store the integer value that will be processed and converted from the input string
	int			sign; //To store the sign of the integer value, and account for the `-` sign if the number is negative

	res = 0; //Initialised to `0` because the conversion starts from th leftmost digit and accumulates the value as it processess each digit in the string. See #1
	sign = 1; //Initialised to `1` because the number is assumed to be `positive` until a negative sign is encounted in the input string
	while (*s == ' ' || (*s >= 9 && *s <= 13)) //Skips whitespace characters from the begining of the string, until a non-whitespace character is found
		s++; //Move the the next character to search for a non-whitespace character
	if (*s == '-' || *s == '+') //Checks for a sign `-` or `+` character
	{
		if (*s == '-') //Indicates a number is negative
			sign = -1; //Update `sign` to `-1`
		s++; //Move to the next character for processing
	}
	while (ft_isdigit(*s)) //When a character is found that represents a digit, loop as long as the current character is a digit
		res = res * 10 + (*s++ - '0'); //Assign to `res` the converted string representation of an integer into an actual integer value. See #2
	return (res * sign); //Return the calculated integer value, multiplying be the value in `sign`, which would make the integer a negative, if sign is `-1`
}

void	print_hex(int n)
{
	char	*hex;
	
	hex = "0123456789abcdef";
	if (n >= 16)
		print_hex(n / 16);
	write(1, &hex[n % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}