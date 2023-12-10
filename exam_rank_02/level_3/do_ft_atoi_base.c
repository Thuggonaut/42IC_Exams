/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

int	ft_atoi_base(const char *str, int base)
{
	int result = 0; //To store the converted digit in base 10
	int sign = 1;

	if (*str == '-') //Check for a minus sign at the start of the string
	{
		sign = -1; //If there's a minus sign, set the sign to negative
		str++;  //Move to the next character for processing
	}
	while (*str) //Loop until the end of the string is reached
	{
		int value; //To store the digit value of the current character

		if (*str >= '0' && *str <= '9') //Check if the current character is a digit
			value = *str - '0'; //Update the value to represent the actual digit, converted by `0`. See #1
		else if (*str >= 'A' && *str <= 'F') //Check if the current character is an uppercase
			value = *str - 'A' + 10;
		else if (*str >= 'a' && *str <= 'f') //If the current character is a lowercase
			value = *str - 'a' + 10;
		else //If character is invalid, break out of loop
			break ;
		if (value >= base) //Check if the digit is within the given base
			break ; //If not, break out of loop
		result = (result * base) + value; //Update the result with the new digit
		str++; //Move to the next character for processing
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

`value = *str - '0'`:
	- e.g., if *str is '5', then
	- '5' - '0' which is
	- 53 - 48 which equals to
	- 5

`value = *str - 'A' + 10`:
	- e.g., if *str is 'C', then
	- 'C' - 'A' + 10 which is
	- 67 - 65 + 10 which equals to
	- 12

`value = *str - 'a' + 10`:
	- e.g., if *str is 'c', then
	- 'c' - 'a' + 10 which is
	- 99 - 97 + 10 which equals to
	- 12
*/

/*
NUMERIC BASE:
"base" refers to the numeric base or radix in which a number is represented. The base determines the number of distinct symbols 
or digits that can be used to represent values in that system. In the case of `ft_atoi_base`, we are working with base-N (where N 
is between 2 and 16) and we need to convert a string representation of a number in this base to its decimal (base-10) equivalent.

Let's break down the assignment:

1. Numeric Base (Radix):
    - In the decimal system (base-10) that we commonly use, we have 10 digits (0-9) to represent all possible values. 
    - In other bases, the number of symbols changes. For example:
        - Binary (base-2) uses 0 and 1.
        - Octal (base-8) uses digits 0 to 7.
        - Hexadecimal (base-16) uses digits 0 to 9 and letters A to F for values 10 to 15.

2. String Representation:
    - Our function will take a string str as input, which contains the number to be converted.
    - This string is composed of characters from the specified set of recognized characters (0-9 and letters a-f or A-F). For instance, 
      "12FDB3" could be the input.

3. Trimming and Character Recognition:
    - We need to trim the characters in the string according to the requested base. For example, if the base is 4, only characters "0," 
      "1," "2," and "3" are recognized. 
    - Similarly, in base 16, both lowercase and uppercase characters "a" to "f" are recognized.

4. Conversion:
    - Our task is to convert the given string representation in the specified base to its equivalent decimal value (base-10). 
    - For instance, if the input is "12FDB3" and the base is 16, we need to convert it to its decimal equivalent.

5. Minus Sign Handling:
    - If the first character of the string is a minus sign ('-'), it indicates a negative number. But this minus sign should only be 
      interpreted if it's the very first character of the string.


#1  The process of converting a number from one base to another involves multiplying each digit by the base raised to the power of the 
    position of the digit (starting from 0 on the right), and summing these products.

    Let's take a look at how bases work, using the number 1011 as an example in different bases:

    Base-2 (binary):  1*2³ + 0*2² + 1*2¹ + 1*2⁰ = 8 + 0 + 2 + 1 = 11
    Base-10 (decimal): 1*10³ + 0*10² + 1*10¹ + 1*10⁰ = 1000 + 0 + 10 + 1 = 1011 
    Base-16 (hexadecimal): 1*16³ + 0*16² + 1*16¹ + 1*16⁰ = 4096 + 0 + 16 + 1 = 4113 

    In each of the examples above, the base is indicated by the subscript next to the number (the small number to the lower right). The 
    base tells us what number system the number is in. 
        - For instance, 1011₂ is "1011 in base-2", while 1011₁₀ is "1011 in base-10", and 1011₁₆ is "1011 in base-16".

#2  Contribution Calculation:
    - When converting to a new base (let's call it Base-N), we need to calculate the contribution of each digit to the new value. 
    - This is done by multiplying the value of the digit by the original base raised to the power of its position. 
    - Mathematically, this is expressed as:

    Contribution = Digit_Value * Original_Base^Position

    Summing Contributions:
    - After calculating the contribution of each digit, we sum up all these contributions to get the final value of the number in the 
      new base. This sum gives us the equivalent value of the original number in the new base.
    - Here's an example to illustrate this process:

    Convert 10101 (Base-2) to Decimal (Base-10):

    1.  The original number is "10101" in binary (Base-2).

    2.  The leftmost digit "1" represents 1 * 2^4 = 16.
        The next digit "0" represents 0 * 2^3 = 0.
        The middle digit "1" represents 1 * 2^2 = 4.
        The next digit "0" represents 0 * 2^1 = 0.
        The rightmost digit "1" represents 1 * 2^0 = 1.

    3.  Calculating contributions:

        16 (from the leftmost "1")
        0 (from the "0")
        4 (from the middle "1")
        0 (from the "0")
        1 (from the rightmost "1")

    4.  Summing contributions: 16 + 0 + 4 + 0 + 1 = 21.

        Therefore, "10101" in binary (Base-2) is equivalent to "21" in decimal (Base-10).
*/