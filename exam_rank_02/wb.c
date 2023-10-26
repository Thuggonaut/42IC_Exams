#include <ctype.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int number = 0;
	int is_negative = 0;

	if (*str == '-')
	{
		is_negative = 1;
		str++;
	}

	while (*str)
	{
		int value;

		if (isdigit(*str))
			value = *str - '0';
		else if (isupper(*str))
			value = *str - 'A' + 10;
		else
			value = *str - 'a' + 10;

		if (value >= str_base)
			break;

		number = number * str_base + value;
		str++;
	}

	if (is_negative)
		number = -number;

	return number;
}


#include <stdio.h> //To call printf() to test function

int main()
{
    printf("%d", ft_atoi_base("19", 16));
}