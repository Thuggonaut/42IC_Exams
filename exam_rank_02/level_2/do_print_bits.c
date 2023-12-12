/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"
*/

#include <unistd.h> //Tp call write()

void	print_bits(unsigned char octet) //Define a function that takes an `unsigned char` which is a `byte` (8 bits), and prints it in `binary` representation (therefore returns `void`)
{
    int i; //Declare in integer variable that will be used to iterate over each `bit` in the `byte`

    i = 8; //`i` is set to `8`, which is the number of `bits` in a `byte`
    while (i--) //Iterate over each `bit`, starting from the MSB (bit 7) and ending with the LSB (bit 0)
    {
        if ((octet >> i) & 1) //The `byte` is right-shifted `i` times, and returns the value of the LSB of `octet`. A bitwise `&` operation is then performed with `1`. This will result in `1` if the `i`th `bit` was set (i.e., it was 1) and `0` if it was not set (i.e., it was 0). See #1
            write(1, "1", 1); //If the result was `1`, the character `1` is written to the standard output
        else
            write(1, "0", 1); //Otherwise, the character '0' is written
    }
}


/*
int main(void)
{
    print_bits(2);    // should print: 00000010 
    write(1, "\n", 1);
    print_bits(255);  // should print: 11111111 
    write(1, "\n", 1);
    print_bits(128);  // should print: 10000000 
    write(1, "\n", 1);
    return (0);
}
*/


/*
This function requires printing each of the `bits` in one `byte` (8 bits): 
  - You will need to use bitwise operations to extract each `bit` of the `unsigned char` and print it. 
  - Starting from the MSB (the leftmost bit). to the LSB (rightmost bit). 
  - If the bit is set (1), print '1', otherwise print '0'.


#1  The code knows which bit of `octet` to compare by using the bitwise AND operation (&) with `1`. This operation will return the value of the LSB of 
    octet.
      - Since `1` only has a single bit set at the rightmost position (LSB) `0000 0001`, the result of this operation will be the LSB of `octet`.
      - For example, if octet is `0010 0110`, the operation `octet & 1` would result in `0` because the LSB of `octet` is `0`.

BITWISE OPERATIONS:

1. Bitwise operations are operations that operate on integers in binary format at the bit level. 
      - "Bit level" refers to operations or processes that are done at the level of individual bits. 
      - A bit, or binary digit, is the smallest unit of data in a computer, and can hold the value of `0` or `1`.
      - When we talk about "bit level", we are talking about the level of abstraction where operations manipulate individual bits. 
      - This is in contrast to higher levels of abstraction, like byte level (where 8 bits are manipulated as one group) or even higher levels where 
        complex data structures like integers, floating point numbers, strings, or objects are manipulated.
2. Bitwise operations allow us to manipulate individual bits of a number.
3. Bitwise operations are faster and use less power than arithmetic operations, which makes them useful in low-level programming, such as device drivers, 
   low-level graphics, and protocol packet assembly.
4. Bitwise logical operators work on the data bit by bit, starting from the least significant bit (LSB), which is the rightmost bit, working towards the 
   most significant bit (MSB), which is the leftmost bit.
5. Most programming languages manipulate groups of 8, 16, or 32 bits, known as bytes. 
      - In computing, a byte is the most commonly used unit of data that represents 8 bits. 
      - A single byte can represent 256 different values (2^8). 
      - Historically, a byte was the number of bits used to encode a single character of text in a computer, which is why it's the smallest addressable 
        unit of memory in many computer architectures.
6. The arithmetic logic unit (ALU), a part of a computer's CPU, performs mathematical operations like addition, subtraction, multiplication, and division 
   at the bit level. For these operations, bitwise operators are used. 
7. Bitwise operators are characters that represent actions (bitwise operations) to be performed on single bits. 


HOW IT ALL MADE SENSE TO ME:
    - Suppose we have:
      int x = 9;

    - Usually an int is 4 bytes, but for this example, we'll pretend it's 1 byte, that has 8 bits.
    - 9 represented in binary is:
      0000 1001

    - Each of these 8 bits, is worth `n` to the power of 2 (2^n).
    - Starting from the LSB:
      1: 2^0 = 1
      0: 2^1 = 2
      0: 2^2 = 4
      1: 2^3 = 8

      0: 2^4 = 16
      0: 2^5 = 32
      0: 2^6 = 64
      0: 2^7 = 128

    - How is `0000 1001` a binary representation of `9` you ask?
    - Imagine `1` means it is set "on", and `0` means it is "off".
    - So, 2^0 = 1 is "on"
    - and 2^3 = 8 is "on"
    - 1 + 8 = 9


COMMON BITWISE OPERATORS:

1. Bitwise `AND` (&): 
    - The bitwise `&` operation takes two bit patterns of equal length and performs the logical `&` operation on each pair of corresponding bits. 
    - The output of bitwise `&` is `1` if the corresponding bits of two operands is `1`. 
    - If either bit of an operand is `0`, the result of the corresponding bit is evaluated to `0`. 
    - For example, bitwise `&` operation of two integers `12` and `25`:
        12 = 0000 1100 
        25 = 0001 1001 
        Bitwise & Operation of 12 and 25:
          0000 1100
        & 0001 1001
          ________
          0000 1000  = 8 


2. Bitwise `OR` Operator (|): 
    - The output of bitwise `|` is `1` if at least one corresponding bit of two operands is `1`. 
    - For example, bitwise `|` operation of `12` and `25`:
        12 = 00001100 
        25 = 00011001 
        Bitwise | Operation of 12 and 25:
          0000 1100
        | 0001 1001
          ________
          0001 1101  = 29 


3. Bitwise `NOT` Operator (~): 
    - Bitwise `~ operator is a unary operator (works on only one operand). 
    - It changes `1` to `0` and `0` to `1`. 
    - This flipping of 1s to 0s makes the binary number a "two's complement".
    - The leftmost bit is used as the sign bit: `0` for positive numbers and `1` for negative numbers. The rest of the bits represent the magnitude of the number. 
    - For example, bitwise `~ Operation of 35:
        35 = 0010 0011 (one's complement)
       ~35 = 1101 1100 (two's complement)
    - Now because the leftmost bit is `1`, this is representing a negative number.
    - If the number is negative, (the bits start with a `1`), the rest of the number is counting upwards from -128 (instead of 128).
        Bitwise ~ Operation of 35:
        0: 2^0 = 1
        0: 2^1 = 2
        1: 2^2 = 4
        1: 2^3 = 8

        1: 2^4 = 16
        0: 2^5 = 32
        1: 2^6 = 64
        1: 2^7 = -128
    
        = -128 + 64 + 16 + 8 + 4
        = -36


4. Bitwise `XOR` Operator (^): 
    - A bitwise `^` is a binary operation that takes two bit patterns of equal length and performs the logical exclusive `|` operation on each pair of 
      corresponding bits. 
    - The result in each position is `1` if only one of the bits is `1`, but will be `0` if both are `0` or both are `1`. 
    - For example:
        12 = 0000 1100 
        25 = 0001 1001 
        Bitwise ^ Operation of 12 and 25:
          0000 1100 
        ^ 0001 1001
          ________
        = 0001 0101 = 21


5. Left Shift (<<): 
    - The left shift operator shifts the bits of the binary representation to the left by a specified number of positions, filling in zeros from the right. 
    - For example:
        12 = 00001100
        12 << 1 (Shift bits to left by 1)
        = (-0)000 1100(+0)
        = 0001 1000 = 24 


6. Right Shift (>>): 
    - The right shift operator shifts the bits of the binary representation to the right by a specified number of positions, discarding bits shifted off. 
    - For example:
        12 = 0000 1100 
        12 >> 2 (Shift bits to right by 2)
        = (+0)(+0)0000 0011(-0)(-0)
        = 0000 0011 = 3


COMPOUND ASSIGNMENT BITWISE OPERATORS:

These operators combine the basic bitwise operators with assignment, allowing you to perform an operation and assign the result in a single step. They are:

1. `&=` (bitwise AND assignment): 
    - Performs a bitwise `&` operation between two expressions and assigns the result to the first expression.
    - a &= b; is equivalent to:
    - a = a & b;

2. `|=` (bitwise OR assignment): 
    - Performs a bitwise `|` operation between two expressions and assigns the result to the first expression.
    - a |= b; is equivalent to:
    - a = a | b;

3. `^=` (bitwise XOR assignment): 
    - Performs a bitwise `^` operation between two expressions and assigns the result to the first expression.
    - a ^= b; is equivalent to:
    - a = a ^ b;

4. `<<=` (left shift assignment): 
    - Shifts the bits of the first expression to the left by the number of places specified by the second expression, and assigns the result to the first 
      expression.
    - a <<= b; is equivalent to:
    - a = a << b;

5. `>>=` (right shift assignment): 
    - Shifts the bits of the first expression to the right by the number of places specified by the second expression, and assigns the result to the first
      expression.
    - a >>= b; is equivalent to:
    - a = a >> b;
*/


