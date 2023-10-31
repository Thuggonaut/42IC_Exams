int	ft_atoi_base(const char *s, int base)
{
	int result = 0; //To store the converted digit in base 10
	int sign = 1;

	if (*s == '-') //Check for a minus sign at the start of the string
	{
		sign = -1; //If there's a minus sign, set the sign to negative
		s++;  //Move to the next character for processing
	}
	while (*s) //Loop until the end of the string is reached
	{
		int value; //To store the digit value of the current character

		if (*s >= '0' && *s <= '9') //Check if the current character is a digit
			value = *s - '0'; //Update the value to represent the actual digit, converted by `0`. See #1
		else if (*s >= 'A' && *s <= 'F') //Check if the current character is an uppercase
			value = *s - 'A' + 10;
		else if (*s >= 'a' && *s <= 'f') //If the current character is a lowercase
			value = *s - 'a' + 10;
		else //If character is invalid, break out of loop
			break ;
		if (value >= base) //Check if the digit is within the given base
			break ; //If not, break out of loop
		result = result * base + value; //Update the result with the new digit
		s++; //Move to the next character for processing
	}
	return (result * sign);
}

/*
#include <stdio.h> //To call printf() to test function

int main(void)
{
    printf("%d\n", ft_atoi_base("19", 16));
	return (0);
}
*/

/*
CONVERSION CALCULATION:

`value = *s - '0'`:
	- e.g., if *s is '5', then
	- '5' - '0' which is
	- 53 - 48 which equals to
	- 5

`value = *s - 'A' + 10`:
	- e.g., if *s is 'C', then
	- 'C' - 'A' + 10 which is
	- 67 - 65 + 10 which equals to
	- 12

`value = *s - 'a' + 10`:
	- e.g., if *s is 'c', then
	- 'c' - 'a' + 10 which is
	- 99 - 97 + 10 which equals to
	- 12
*/
