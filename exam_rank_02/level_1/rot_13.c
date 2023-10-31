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

	- Original character: 'x' (ASCII value: 120)

	- Encryption key (k): 5

	- For a lowercase letter 'x':

	- Subtract the ASCII value of 'a' (97) from the original character:

	- 120 (original ASCII value) - 97 ('a') = 23
	- Add the encryption key (k) to the result:

	- 23 + 5 (k) = 28
	- Apply the modulo operation % 26 to ensure wrapping around the alphabet:

	- 28 % 26 = 2
	- Add the result to the ASCII value of 'a' to get the shifted character:

	- 2 + 97 ('a') = 99
	- The final result, 99, corresponds to the ASCII value of 'c,' which is the encrypted character.

	- So, when you shift 'x' by 5 positions using the Caesar cipher, it becomes 'c.'
*/

#include <unistd.h> //To call write()

void caesar_cipher(char *s, int k) //Define a function that takes a string and rotate each alphabet character by `k` positions
{
    while (*s) //Loop until the end of the string is reached
    {
        //FORMULA: *res = ((((ASCI - 'A' or 'a') + key) %26) + 'A' or 'a'). Remember, if `a % b` where `a`is less than `b`, the result is `a` with a remainder of `0`
		if (*s >= 'a' && *s <= 'z') //Checks for a lowercase alphabet character
            *s = (((*s - 'a') + k % 26) + 'a'); //Current character is rotated by `k` positions
        else if (*s >= 'A' && *s <= 'Z') //Checks for an uppercase alphabet character
            *s = (((*s - 'A') + k % 26) + 'A'); //Current character is rotated by `k` positions
        write(1, s, 1); //Write to the standard output, the rotated alphabet character, or, the non-alphabet character
        s++; //Move to the next character of the string
    }
}

int main(int argc, char **argv) //argv is a pointer to an array of strings. By using a double pointer char **argv, the program can access and retrieve each individual argument as a null-terminated string
{
    int rotate; //Declare variable for rotation amount
    
    rotate = 5; //The number of rotation
    if (argc == 2) //Perform operations only if argc is two, meaning there is only one argument in addition to the program name 
        caesar_cipher(argv[1], rotate); //Rotate each alphabet character of the string
    write(1, "\n", 1); //If the number of arguments is not 1, the program displays a newline
    return (0);
}
