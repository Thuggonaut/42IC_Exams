#include <unistd.h>



int	ft_putnbr_base(unsigned long long nb, const char *base) //Takes an unsigned long long integer `nb` and a pointer to a constant character array `base` that represents the base for conversion
{
	unsigned long long	len; //To store the length of the base
	int			count; //To keep track of the total number of characters printed

	count = 0;
	len = ft_strlen(base);
	if (nb >= len) //If this condition is true, it means that the current digit of nb needs to be divided by the base to obtain the next digit in the converted representation
		count += ft_putnbr_base(nb / len, base); //This recursive call effectively converts the number into the specified base. See #1
	count += ft_putchar(base[nb % len]); //Print the characters in the base one by one, from least significant digit to most significant digit. See #2
	return (count);
}


int	ft_handle_hexlower(va_list ap) //`ap` is a `va_list` pointer that is passed as an argument. Inside the function, this pointer is used to access the variable arguments
{
	unsigned int	n; //To store the value of the next argument retrieved from `ap` for processing

	n = va_arg(ap, unsigned int); //Retrieve an unsigned integer argument from `ap` and assign it to `n`
	return (ft_putnbr_base(n, "0123456789abcdef")); //Converts the unsigned integer `n` into a string representation using the provided base. See #1
}

int	ft_handle_hexupper(va_list ap)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	return (ft_putnbr_base(n, "0123456789ABCDEF")); //See #3
}

/*
#1	Here's how the recursive call works to convert the number into the specified base:
	Suppose we have the number nb = 42 and the base `base` = "0123456789ABCDEF", which represents a hexadecimal base (base 16):
		- Initially, `nb` is greater than or equal to the length of the base (16 in this case), so the recursion starts.
		- `nb` is divided by `len`. The result of this division represents the quotient of the division:
		  	- In the first recursive call, `nb` is divided by 16. The quotient is `2` (integer division), and the remainder is 
		 	  `10`.
		- The recursive call `ft_putnbr_base(nb / len, base)` is made, passing the quotient as the new value for nb:
		  	- `ft_putnbr_base(2, base)` 
		- The recursive call will continue until `nb` is less than the length of the base. At that point, the recursion
		  stops, and the function starts returning back:
		  	- Now, `nb = 2` is less than the length of the base, so the recursion stops, and the function starts returning back.

#2	Here's how the characters in the base is printed:
		- After the recursive call `ft_putnbr_base(nb / len, base)`, the remainder of `nb / len` is obtained using the modulus 
		  operator `%` (`nb % len`). This remainder represents the index of the character in the base that corresponds to the 
		  current digit being converted.
		- The obtained remainder is then passed as an argument to `ft_putchar()`, responsible for printing a single character.
		- `ft_putchar()` prints the character corresponding to the index obtained from the remainder. For example, if the 
		  remainder is `0`, it would print the first character in the base; if the remainder is `1`, it would print the second 
		  character, and so on:  
		  	- In the recursive call, the remainder `10` is used as an index to access the character `'A'` from the base string. 
		  	- The character is printed.
		- The return value of `ft_putchar()` represents the number of characters printed by that function call, which is 1 
		  (as it prints a single character).
		- As the recursive calls return, the return value of `ft_putchar()`(which represents the number of characters printed in 
		  the recursive call) is then added  to `count`. This way, `count` keeps track of the total number of characters printed 
		  throughout the recursive calls:
		  	- The return value (which is `1` in this case, representing the single character printed) is added to `count`.
		  	- Finally, the function returns `count`, which is 1. This means that 1 character has been printed, representing the 
		  	  hexadecimal value for `42`, which is `'A'`.
		- So, in this example, the code converts the number `42` into its hexadecimal representation, which is `'A'`.

#3	`ft_putnbr_base()` converts an unsigned integer `n` into a string representation using a specific base. In this case, the base 
	is hexadecimal with lowercase letters.
		- The first argument passed to `ft_putnbr_base` is `n`, which represents the unsigned integer that needs to be 
		  converted.
		- The second argument passed to `ft_putnbr_base` is the string `"0123456789abcdef"`. This string serves as the base for 
		  the conversion. In hexadecimal, the base is composed of the digits 0-9 followed by lowercase letters a-f.
			* In computer science and mathematics, hexadecimal (or hex) is a numbering system that uses a base of 16. It is 
			  commonly used to represent binary values in a more compact and human-readable form. 
			* Hexadecimal digits range from 0 to 15, and since the decimal system only has digits from 0 to 9, additional 
			  symbols are needed to represent values from 10 to 15. After digit 9, the alphabetical characters a to f 					  
			  (lowercase) are used to represent the values 10 to 15, respectively.
			* So, the string "0123456789abcdef" is used as the base for the hexadecimal conversion.
		- The return value of `ft_putnbr_base` represents the resulting string after the conversion. In other words, it returns 
		  the hexadecimal representation of the unsigned integer `n` in lowercase.
*/