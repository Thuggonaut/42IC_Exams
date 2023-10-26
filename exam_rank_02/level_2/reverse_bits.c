/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
*/

unsigned char reverse_bits(unsigned char octet) //Define a function that takes an `unsigned char` (1 byte) as an argument and returns it reversed
{
    unsigned char reversed; //Declare an unsigned char variable to store the reversed bits
    int i; //Declare in integer variable that will be used to iterate over each `bit` in the `byte`

	reversed = 0; //Initialised to `0` because we haven't reversed the bit yet. reversed = `0000 0000`
    i = 8; //`i` is set to `8`, which is the number of `bits` in a `byte`
	while (i--) //Iterate over each `bit`, starting from the MSB (bit 7) and ending with the LSB (bit 0)
    {
        reversed <<= 1; //Shift the `reversed` byte left to make room for the next bit from `octet`. See #1
        reversed |= octet & 1; //Add the current bit of `octet` to `reversed`. See #2
        octet >>= 1; //Shift the original byte right. See #3
    }
    return (reversed);
}

/*
#include <stdio.h>

int main()
{
    unsigned char x = 38;
    printf("%d", reverse_bits(x)); //Prints 100, which is 01100100 in binary
    return (0);
}
*/

/*
See notes regarding COMPOUND ASSIGNMENT BITWISE OPERATORS in `print_bits.c` in Exam Rank02 Level 2.


#1	If the `reversed` byte is not shifted left by one bit to make room for the next bit from the `octet`, the reversed byte will not be able to store the 
	reversed bits correctly. Instead, the new bit will always replace the LSB of the `reversed byte`, and the previous bits added from the prior iteration
	will be lost.

#2  The code knows which bit of `octet` to compare by using the bitwise AND operation (&) with `1`. This operation will return the value of the LSB of 
    octet.
      - Since `1` only has a single bit set at the rightmost position (LSB) `0000 0001`, the result of this operation will be the LSB of `octet`.
      - For example, if octet is `0010 0110`, the operation `octet & 1` would result in `0` because the LSB of `octet` is `0`.
	  - In the next iteration, `octet` is right-shifted by one bit (octet >>= 1), so the second bit from the right becomes the LSB. This process repeats 
	    for each bit in `octet`, effectively scanning `octet` from right to left.
	  - Here's a visual representation of the process for octet = 0010 0110:

		0010 0110 & 0000 0001 => 0
		0001 0011 & 0000 0001 => 1
		0000 1001 & 0000 0001 => 1
		0000 0100 & 0000 0001 => 0
		0000 0010 & 0000 0001 => 0
		0000 0001 & 0000 0001 => 1
		0000 0000 & 0000 0001 => 0
		0000 0000 & 0000 0001 => 0


#3	Before the loop starts:
	
		octet = 0010 0110
		reversed = 0000 0000
		i = 8

	First iteration (i = 7):
		octet & 1 = **0**
		reversed <<= 1 => 0000 0000
		reversed |= **0** => 0000 0000
		octet >>= 1 => 0001 0011 (**0** discarded)

	Second iteration (i = 6):
		octet & 1 = **1**
		reversed <<= 1 => 0000 0000
		reversed |= **1** => 0000 0001
		octet >>= 1 => 0000 1001 (**1** discarded)

	Third iteration (i = 5):
		octet & 1 = **1**
		reversed <<= 1 => 0000 0010
		reversed |= **1** => 0000 0011
		octet >>= 1 => 0000 0100 (**1** discarded)

	Fourth iteration (i = 4):
		octet & 1 = **0**
		reversed <<= 1 => 0000 0110
		reversed |= **0** => 0000 0110
		octet >>= 1 => 0000 0010 (**0** discarded)

	Fifth iteration (i = 3):
		octet & 1 = **0**
		reversed <<= 1 => 0000 1100
		reversed |= **0** => 0000 1100
		octet >>= 1 => 0000 0001 (**0** discarded)

	Sixth iteration (i = 2):
		octet & 1 = **1**
		reversed <<= 1 => 0001 1000
		reversed |= **1** => 0001 1001
		octet >>= 1 => 0000 0000 (**1** discarded)
		
	Seventh iteration (i = 1):
		octet & 1 = **0**
		reversed <<= 1 => 0011 0010
		reversed |= **0** => 0011 0010
		octet >>= 1 => 0000 0000 (**0** discarded)

	Eighth iteration (i = 0):
		octet & 1 = **0**
		reversed <<= 1 => 0110 0100
		reversed |= **0** => 0110 0100
		octet >>= 1 => 0000 0000 (**0** discarded)

	After the loop ends (i = -1):
		reversed = 0110 0100 (100 in decimal)
*/
