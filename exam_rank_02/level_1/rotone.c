/*
Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
*/

#include <unistd.h> //To call write()

void rotate(char *s, int k) //Define a function that takes a string and rotate each alphabet character by `k` positions
{
    while (*s) //Loop until the end of the string is reached
    {
        //FORMULA: *res = ((((ASCI - 'A' or 'a') + key) %26) + 'A' or 'a'). Remember, if `a % b` where `a`is less than `b`, the result is `a` with a remainder of `0`
		if (*s >= 'a' && *s <= 'z') //Checks for a lowercase alphabet character
            *s = (((*s - 'a') + k % 26) + 'a'); //Current character is rotated by `k` positions
        else if (*s >= 'A' && *s <= 'Z') //Checks for an uppercase alphabet character
            *s = (((*s - 'A') + k % 26) + 'A'); //Current character is rotated by `k` positions
        write(1, s++, 1); //Write to the standard output, the rotated alphabet character, or, the non-alphabet character before moving to the next
    }
}

int main(int argc, char **argv) //argv is a pointer to an array of strings. By using a double pointer char **argv, the program can access and retrieve each individual argument as a null-terminated string
{
    int key; //Declare variable for rotation amount
    
    key = 1; //The number of rotation
    if (argc == 2) //Perform operations only if argc is two, meaning there is only one argument in addition to the program name 
        rotate(argv[1], key); //Rotate each alphabet character of the string
    write(1, "\n", 1); //If the number of arguments is not 1, the program displays a newline
    return (0);
}