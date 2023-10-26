/*
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>
*/

/*
Use Caesar cipher algorithm

ci = (pi + k) % 26

The ciphertext, is each alphabetical character in the plaintext “rotated” by k positions. Preserve case and non alphabetical characters
The modulus operator % 26 restricts the value to the range of 0-25, which corresponds to the positions in the alphabet

Let's consider a lowercase letter 'x' as an example. The ASCII value of 'x' is 120

Suppose we want to shift 'x' by 5 positions. Without using % 26, the calculation would be as follows:

Add the encryption key to the ASCII value of 'x': 120 + 5 = 125
However, `125` is outside the range of lowercase letters in ASCII. The ASCII values for lowercase letters 'a' to 'z' range from 97 to 122.

To keep the shifted position within the valid range, we apply % 26 to the calculation:

Add the encryption key to the ASCII value of 'x': 120 + 5 = 125.
Apply % 26 to the result: 125 % 26 = 21.
The result, 21, is within the valid range of lowercase letters. 
21((number + k) %26) + 97('a') = 118. It corresponds to the ASCII value of 'v', which is the encrypted letter when shifting 'x' by 5 positions.

How %26 is calculated:

125 / 26 = 4.807692307692308 (Perform integer division number / 26)
The quotient is 4
4 * 26 = 104 (Multiply the quotient by 26)
125 - 104 = 21 (Subtract the result from the original number)
Result: 21 (the remainder of (number + k) %26)
*/

#include <unistd.h> //To call write()

void caesar_cipher(char *s, int k) //Define a function that takes a string and rotate each alphabet character by `k` positions
{
    char c; //`c` is declared, for the processing of each character in the string. See #1

    while (*s) //Loop until the end of the string is reached
    {
        c = *s; //The current character is assigned to `c`
        if (c >= 'a' && c <= 'z') //Checks for a lowercase alphabet character
            c = (((c - 'a' + k) % 26) + 'a'); //Current character is rotated by `k` positions
        else if (c >= 'A' && c <= 'Z') //Checks for an uppercase alphabet character
            c = (((c - 'A' + k) % 26) + 'A'); //Current character is rotated by `k` positions
        write(1, &c, 1); //Write to the standard output, the rotated alphabet character, or, the non-alphabet character
        s++; //Move to the next character of the string
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv) //argv is a pointer to an array of strings. By using a double pointer char **argv, the program can access and retrieve each individual argument as a null-terminated string
{
    int rotate; //Declare variable for rotation amount
    
    rotate = 13; //The number of rotation
    if (argc == 2) //Perform operations only if argc is two, meaning there is only one argument in addition to the program name 
        caesar_cipher(argv[1], rotate); //Rotate each alphabet character of the string
    write(1, "\n", 1); //If the number of arguments is not 1, the program displays a newline
    return (0);
}


/*
#1	The `char c` is used as a temporary variable to hold the current character being processed from the string. This is done for a couple of reasons:
		- It allows you to modify the character (change its case) without affecting the original string. This is important if you want to keep the 
  		  original string unchanged, which is often the case in C programming.
		- It simplifies the code by avoiding repeated dereferencing of the pointer `str`. Instead of writing *str multiple times in the code, you 
                  can just use `c`.
*/

