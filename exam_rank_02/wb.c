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

// int bit = 8
// unsigned char res = 0
// while i--
// res <<= 1; res != octect & 1; octet >>= 1;

unsigned char	reverse_bits(unsigned char octet)
{
	int				bit = 8;
	unsigned char	res = 0;

	while (bit--)
	{
		res <<= 1;
		res |= octet & 1;
		octet >>= 1;
	}
}