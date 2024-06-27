# LEVEL 3

### add_prime_sum
- ft_atoi, putn, is_prime
- is_prime, checks for prime numbers
	- starting from `i = 2`
	- loop from `i * i` to n to check for primes, squaring i first
	- if n is divisible by i, `n % i == 0`, then n is not prime
	- otherwise, if there is a remainder, n is prime

### ft_atoi_base
- `int value` to store digit value of current character
- check for `-`
- iterate through str, check for digits, lc and uc
	- break out of loop if char invalid
	- break if `value >= base`
	- `res = (res * base) + value`

### lcm
- return 0 if either number is 0
- assign bigger number to `unsigned int n`
- `while (1)` infinate loop
	- n++ until `n % a == 0 && n % b == 0`

### pgcd
- Finds the greatest common divisor (GCD) of two numbers: the highest number that both numbers can be divided by exactly.
- like swap()
- loop until b = 0 `b != 0`
	- temp = b, `b = a % b`, a = temp
- `return a`, the gcd

### ft_range
- `int len` uses `abs()`
- `int *tmp` to preserve pointer to start of array
- int main()
	- while `len-- > 0`, printf `*array++`;

### print_hex
- ft_atoi
- `char *hex`
- use recursion, `if (n >= 16)`, just like ft_putnbr, but instead of `/ 10`, it's 16
- write `&hex[n % 16]`


# LEVEL 4

### fprime
- `int 1 = 2` the first prime number
- if n = 1, print it
- loop until n == 1 `while (n > 1)`
	- if `n % i == 0` no remainder mean i is a prime factor
		- print i
		- `n /= i` update n
		- if `n > 1` there are more prime factors
			- print `*`
	- else `i++`

### rev_wstr
- `int len` for string length
- `int end` index of last char
- `int start` index of first char
- `int flag` index of start, if start = 0, there are no more words
- while `len >= 0` iterate through string
	- skip ws from end of string using `len--`
	- end = len
	- find start of current word using `len--`
	- start = len + 1 (come back from len--)
	- flag = start (track index of string so far)
	- print word `while (start <= end)` write &s[start]
	- `if (flag)` print space

### rostring
- `int len` to store first word
- `char *first` to duplicate first word
- `char *f` to preserve pointer of first
- `char *s` to preserve pointer of original str
- skip leading ws
- iterate through first word by incrementing len and *s
- malloc first word
	- assign *f as *first
	- coppy first word using *str and len
	- null terminate *f
- print remaining string
	- first check for end of words and printing a space
	- then print other characters
- print first word

