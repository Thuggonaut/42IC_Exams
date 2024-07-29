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



int main(void)
{
    print_bits(6903);    
    write(1, "\n", 1);
    /*print_bits(255);  // should print: 11111111 
    write(1, "\n", 1);
    print_bits(128);  // should print: 10000000 
    write(1, "\n", 1);*/
    return (0);
}