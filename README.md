EXAM PREP:

**DEBUG WITH \0
```
int     main(int argc, char **argv)
{
        char    *s = argv[1];

        if (argc == 2)
                rev_print(argv[1]);
        write(1, "\n", 1);
        while (*s)
        {
                printf("%c (%d)\n", *s, *s);
                s++;
        }
        printf("\\0 (%d)\n", *s); //This line should output 0 as the ascii value. Any different will imply an error or misinterpretation of the \0 handling in the code
        return (0);
}
```

# ft_swap *tmp vs tmp
# repeat_alpha
# % vs /
# rotate formula
# ft_putnbr
# ft_atoi
# ft_atoi_base
# ft_range
# lcm
# ft_itoa
- list manipulation
# bitwise operations
# prime vs composite numbers
# print_hex
- powers (n == 1); Base, exponents;
# flood_fill
# ft_split
# rev_wstr
# rostring


## ft_swap 
- Account for:
	1. *tmp vs tmp
	2. `int		tmp;` doesn't need a pointer because it temporarily stores a regular integer.
	3. *a and *b are pointers because the values they point to, can be modified. 


## repeat_alpha
- Account for:
	1. `putchar_times(char c, int n)`
	2. formula for `n`:
		- LC: `(*s + 1) - 'a'`
		- UC: `(*s + 1) - 'A'`


## % vs /
1. `\` integer division, yields the quotient without the remainder.
2. `%` modulo, yields the remainder, not the quotient. 
	- result will be 0 if division is even.
	- result will be the dividend, if it is smaller than the divisor. 


## rotate formula
- Account for:
	1. UC and LC
	2. `*s = (((*s - 'A' + key) % 26) + 'A')`


## ft_putnbr
- Account for:
	1. `int digit;` stores the digit, one at a time
	2. Use recursion, `if()` loop with `(n / 10)` to "descend" through, and removing each digit, from the rightmost, to the leftmost.
	3. At base case, when `n < 9`, `digit` is updated to the ASCII value of the char represenation of the digit, e.g. `1` becomes `"1"` which is `49` in ASCII.
	4. Print the ASCII value (e.g. integer `49`) at the address of &digit. 
	5. Go back to each recursive call, printing the ASCII rightmost digit of `n` until all digits have printed, from leftmost, to rightmost.


## ft_atoi
- Remember, it only converts the inital portion of a string: "*&!+12345. 6789" will print "12345". 
- Account for:
	1. `int		sign;` for negative values
	2. `int		result;` initialized to `0` for the formula to work, and stores the converted value
	3. Skip leading whitespace between 9 and 13, and including `' '` and `'+'`.
	4. Search for chars that represent digits.
	5. If found, convert the chars to integers. `res` will be an accumulated value starting from `res = 0`.
		`res = (res * 10) + (*s++ - '0');`
	6. If no digits found, return (0). 


## ft_atoi_base
- Account for:
	1. `int result` to store final result, and is accumulated.
	2. `int sign`
	3. `int value` to store digit value of current character when iterating through each character.
	4. Check for each character, if digit, LC or UC. Formula of `value` for each:
		- digit: `*s - ‘0’`
		- LC: `*s - ‘a’ + 10`
		- UC: `*s - ‘A’ + 10`
		- Where `10` represents the base the assignment asks us to convert to. 
	5. Break program if character is not digit, UC or LC, or if value is >= the base.
	6. Result formula: `res = (res * base) + value`, the same as ft_atoi()


## ft_range:
- Account for:
	1. `abs()` to get the absoloute value of `len = (end - start + 1)` when end is a negative number.
	2. `temp` variable to iterate the array, and preserve the pointer to the begining of `array`.
	3. Use `len` to iterate.
		- Check if range increases, `start <= end`
		- Else the range decreases, in which case, `start` value decreases.
	4. We're printing from the leftmost to the right, hence `tmp = start`
## ft_rrange
- Is the same, except in reverse
- Everything the same except:
	1. `len = start - end`
	2. `end` decrements or increments depending if `end` increases or dereases range. Recall, we're printing from the rightmost to left, hence `tmp = end`


## lcm
- Need to find the lowest common multiple.
	1. Check conditions for returning 0.
	2. `n` variable to store possible common multiples
	3. assign to `n` the larger value between `a` and `b`
	3. Create infinite loop, `while (1)` (because non-zero values always true)
		- increment `n` until a common multiple is found
		- where `n` is divisble by both `a` and `b` with no remainders


## ft_itoa
- Account for:
	1. `len_digits()`
		- `len` variable to return
		- account for a negative number
		- account for `0`
		- how to iterate through each digit to retrieve the length? `n /= 10` until `n == 0`
	2. `ft_itoa()`
		- `str` variable to return
		- account for longer integer types which int cannot cover
		- length of number is needed to allocate enough memory for the comverted string
		- account for negative numbers, both in value, and in the string
		- account for if number is `0`
		- assign the digit value, for each string character. Formula:
			- `*(str + len - 1) = n % 10 + '0'`
			- `n /= 10`
			- decrement `len`, assigning each digit, backwards.


## list manipulation
- Testing:
	1. Declare individual nodes
		- allocate memory for each node `malloc(sizeof(t_list)`
		- assign the data
		- assign the next pointers
		- printf the list function or the list data
		- free all the nodes


## bitwise operations
- Each bit's worth:
	1. In binary, each bit is worth `n` to the power of 2: `2^n`
	2. `n` is the position of the bit from the rightmost bit to the leftmost. 
	3. `1` is "on", `0` is "off".
- Operators:
	1. `&` "AND" results in `1` if both bits are `1`, else it'll result in `0`.
	2. `|` "OR" results in `1` if either or bits is `1`.
	3. `~` "NOT" flips the bits `1`s to `0`s, making the binary number a "two's complement", where the leftmost bit idicates a positive `0` or negative `1`. 
	4. `^` "XOR" results in `1` if either bit is `1`, and `0` if both bits are the same, e.g. both are `1` or `0`.
	5. `<<` shifts the bits left, filling in `0`s from the right.
	6. `>>` shifts the bits right, filling in `0`s from the left. 
- Compound assignment:
	1. Each operator can be used with `=` e.g. `a &= b`, equivalent to `a = a & b`.
- Bitmask:
	1. 15 =  0000 1111, but can also use >> 4
	2. 240 = 1111 0000, but can also use << 4


## prime vs composite numbers
- Prime numbers:
	1. A number greater than 1, but is not the product of multiplying two smaller numbers: `2, 3, 5, 7, 11, 13, ...`.
	2. Has only two distinct positive divisors: 1 and itself.
- Composite numbers:
	1. A number that has divisors other than 1 and itself, and can be divided evenly: `4, 6, 8, 9, 10, 12, ...`.
- Prime factors:
	1.  Are the prime numbers that divide a given number exactly, without leaving a remainder.
		- For example, the prime factors of 12 are 2, 2, and 3, because 2 * 2 * 3 equals 12.
	2. The prime factors of a number are the building blocks that, when multiplied together, give the original number
- ## add_prime_sum():
- Re prime numbers.
	1. `ft_atoi()` to convert `argv[1]`.
	2. `ft_putnbr()` to print the sum result.
	3. `is_prime()` to check for prime numbers:
		- Account for:
			1. `unsigned int	i` because needs to be positive. 
			2. Check if n is 1 or negative, not a prime, return (0)
			3. `i` initialised to `2` to look for factors (n divisible by i with no remainder), from i to n.
			4. Iterate from i to n, return (0) if `n % i == 0`
			5. Return (1) if n is prime.
	4. `add_prime_sum()` to add all the prime of a number:
		- Account for:
			1. `unsigned int	n` to store converted atoi
			2. `unsigned int	sum` to store the sum result, initialised to `0` for accumulation
			3. `unsigned int	i` to iterate. Initialised to `2`, the smallest prime
			4. Iterate from 2 to n, checking for primes, and accumulate sum
			5. print `sum` at the end of the iterations.
- ## fprime():
- Re prime factors.
	1. `int	i` to iterate. Initialised to `2`, the smallest prime
	2. ensure `1` is printed if `n == 1`
	3. Loop until `n = 1` because any number multiplied by 1 is valid.
	4. if `n % i == 0`, it is divided evenly, and we print the first prime factor. 
	5. if `n /= i > 1`, then `n` needs to be multiplied by another prime factor, another building block, to give us the original number.
		- print the `*` before retrieving the next prime factor. 
	6. increment `i` if needed, to find the next prime factor where there are no remainders. 
	7. ensure `fprime()` is called when input is a positive number. 


## print_hex
- Account for:
	1. `ft_atoi()` since argv is type char
	2. if n > 16 `print_hex()` recursively calls itself with `n / 16` becuase, 'base 16'
	3. `char array` that contains the base 16 values
	4. write hex[n % 16]

## powers, base, exponents
- lowest power of 2 is 1
- Always check if n is 0


## flood_fill
- Use recursion.
- Account for:
	1. variable `target` to store the begin points of the array, e.g. `tab[x][y]`
	2. `fill()` helper function
		- ensure each x and y points are within ranges `0 to size`
		- ensure the current points meet the target points
		- if conditions met, assign the current points the character to be replaced with
		- recursively call itself with:
			1. `x + 1, y` filling the right of x
			2. `x - 1, y` filling the left of x
			3. `x, y + 1` filling the top of y
			4. `x, y - 1` filling the bottom of y
	3. Call `fill()` with the begin points
	4. Caution where x and y is placed, e.g., must be `tab[y][x]` not `tab[x][y]`


## rev_wstr
- Account for:
	1. `ft_strlen()` and use len-- to iterate backwards
	2. `int end` to track last character of a word
	3. `int start` to tract first character
	4. `int flag` which = `start` to keep track of the last word. `0` implies the end of the string. 
	5. Make sure the `\0` isn't printed.


## rostring
- Account for:
	1. `malloc` first word to print last
		- Length of first word
	2. Temp variables for original string and for first word to preserve pointers and be able to iterate
	**NOTE: Order of executions**
	3. Skip leading whitespace and "discard"
	4. Check for first word and length
	5. Iterate through remaining string, and again, caution re order of conditions
		- for an word ending character, print 1 space, remember the '\0' at end of string, need space also
		- else write the character as is
	6. Print the first word


## ft_split
- Account for:
	1. `word_count()`
	2. `ft_split()`
		- word count
		- **result array
		- array index [i]
		1. skip leading whitespace
		2. Break if end of string
		3. word start index
		4. word length
		5. allocate memory of word in array[i]
		6. copy current word
		7. null terminate word, move to next
