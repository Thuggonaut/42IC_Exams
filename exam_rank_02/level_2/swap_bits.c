/*
Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100

*/


 unsigned char	swap_bits(unsigned char octet) //Define a function that takes an `unsigned char`, and return the bits swapped
{
    return ((octet & 15) << 4 | (octet & 240) >> 4); //See #1 for the rundown. See also NOTE: re why bit mask (used here) is not needed
}


/*
#include <stdio.h>

int main()
{
    unsigned char x = 38; //38 is 0010 0110
    printf("%d", swap_bits(x)); //Prints 98, which is 0110 0010 in binary
    return (0);
}
*/


/*
BIT MASK:
    - a way to highlight or shadow bits in a byte.
    - is a binary pattern used to modify another binary pattern using bitwise operations.
    - For example, say we have a binary representation of 38, and we only want the last four bits (right nibble).
    - We use a mask of `15` (`0000 1111` in binary) with the `&` bitwise operator
        0010 0110 
      & 0000 1111 (the bit mask)
        _________
      = 0000 0110
    - This essentially highlights all the bits of `35` where its corresponding bits are `set`, as `1`, like it is "on", and the bits 
      where its corresponding bits are `0`, are shadowed. 

    - If instead, we only wanted the first four bits (left nibble), we use a mask of `240` (`1111 0000` in binary), with the `&` 
      bitwise operator:
        0010 0110 
      & 1111 0000 (the bit mask)
        _________
      = 0010 0000
    - This highlights all the bits of `35` where its corresponding bits are `set`, as `1`, like it is "on", and the bits where its 
      corresponding bits are `0`, are shadowed.     


NOTE: 
    While the swap_bits() function doesn't need a mask because it only uses shift operations, masks are still a very useful tool for
    manipulating bits in other situations. Recall, A mask is used when you want to isolate (mask out) certain bits of a number, or 
    when you want to set certain bits to a specific value. In this case, swap_bits() would work as:

    unsigned char   swap_bits(unsigned char octet)
    {
	    return ((octet >> 4) | (octet << 4));
    }


#1  The rundown:

    1. `octet & 15`:
        - The `&` operator performs a bitwise `AND` operation. 
        - `15` in binary is `00001111`. 
        - This operation will shadow the first four bits (left nibble) and keep the last four bits (right nibble) of the `octet`.
        - We get `0000 0110`

    2. `<< 4`:
        - The `<<` operator is a bitwise shift operator that shifts the bits of the number on the left to the left by the number of 
          positions specified on the right. 
        - This operation will move the right nibble (which we preserved in step 1) to the left by four positions.
        - We get `0110 0000`

    3. `octet & 240`:
        - Again, the `&` operator performs a bitwise `AND` operation. 
        - `240` in binary is `11110000`. 
        - This operation will shadow the last four bits (right nibble) and keep the first four bits (left nibble) of the `octet`.
        - We get `0010 0000`

    4. `>> 4`:
        - The `>>` operator is a bitwise shift operator that shifts the bits of the number on the left to the right by the number of
          positions specified on the right. 
        - This operation will move the left nibble (which we preserved in step 3) to the right by four positions.
        - We get `0000 0010`

    5. `|`:
        - The `|` operator performs a bitwise `OR` operation. 
        - This operation will combine the results from step 2 and step 4 into the final result, effectively swapping the two nibbles
          of the octet:
            0110 0000  ((octet & 15) << 4)
          | 0000 0010  ((octet & 240) >> 4)
            _________
          = 0110 0010
*/
