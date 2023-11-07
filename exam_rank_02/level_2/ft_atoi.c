/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/

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

/*
int main()
{
    char *num1 = "123";
    char *num2 = "456";
    int res;
    res = ft_atoi(num1) * ft_atoi(num2);
    printf("%d\n", res);
}

#1  The result variable needs to be initialized with `0` because it is used to accumulate the integer value represented by the string. 
        - Initializing it with `0` ensures that the accumulation starts from a neutral value, and it can be updated correctly as we 
          iterate through the digits in the input string.

    Here's how the loop works for this example:
        - result starts at 0.
        - For the first digit '1', result is updated to: 0 * 10 + (1 - 0) = 1.
        - For the second digit '2', result is updated to: 1 * 10 + (2 - 0) = 12.
        - For the third digit '3', result is updated to: 12 * 10 + (3 - 0) = 123.

#2  Let's look at another example. Suppose we have `const char *str = "-456"`
    
    sign = -1
    
    First iteration (*str = '4'):
        - `ft_isdigit(*str)` returns `1`, so the loop continues.
        - `result = result * 10 + (*str++ - '0')` translates to 
        - `result = 0 * 10 + (52 - 48)`, which results in 
        - `result = 4`.

    The pointer `str` is incremented to the next character.

    Second iteration (*str = '5'):
        - `ft_isdigit(*str)` returns `1`, so the loop continues.
        - `result = result * 10 + (*str++ - '0')` translates to 
        - `result = 4 * 10 + (53 - 48)`, which results in 
        - `result = 45`.

    The pointer `str` is incremented to the next character.

    Third iteration (*str = '6'):
        - `ft_isdigit(*str)` returns `1`, so the loop continues.
        - `result = result * 10 + (*str++ - '0')` translates to r
        - `result = 45 * 10 + (54 - 48)`, which results in 
        - `result = 456`.

    The pointer `str` is incremented to the next character (null terminator).

    The loop ends because there are no more digit characters in the string.
    The function returns the final result, taking into account the sign:
        - `return (result * sign)`; which translates to
        - `return (456 * -1)` which returns
        - `-456`
*/
