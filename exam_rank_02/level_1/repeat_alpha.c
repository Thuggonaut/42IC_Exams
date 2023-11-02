/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>

*/

#include <unistd.h> //To call write()

void    putchar_times(char c, int n) //Define a function that write the character `c` to the standard output `n` number of times
{
    while (n > 0) //Loop until `n` becomes `0`
    {
        write(1, &c, 1); //Print the character at the address of `c` to the standard output
        --n; //Pre-decrement the number of times needed for printing. See #1
    }
}

void    repeat_alpha(char *s) //Define a function that takes a pointer to a chracter array (a string) and iterate through
{
    while (*s) //Loop until the end of the string is reached
    {
        if (*s >= 'a' && *s <= 'z') //If the character is a lowercase character
            putchar_times(*s, *s + 1 - 'a'); //Print the current character, `*s + 1 - 'a'` number of times (the position of the character in the alphabet (e.g., 'd'(ASCII 100) + 1(101) - 'a'(ASCII 97) = 4, making it position three))
        else if (*s >= 'A' && *s <= 'Z') //If the character is a uppercase character
            putchar_times(*s, *s + 1 - 'A'); //Print the current character, `*s + 1 - 'a'` number of times (the position of the character in the alphabet (e.g., 'T'(ASCII 84) + 1(85) - 'A'(ASCII 65) = 20, making it position 20))
        else
            write(1, s, 1); //If the current character is not alphabetical, print the character to the standard output
        s++; //Move to the next character for processing
    }
}

int main(int argc, char **argv) //Write a program that takes argc number of command-line arguments, and a pointer to argv array of strings containing the CL arguments
{
    if (argc == 2) //Perform repeat_alpha() on argv[1] only if argc is two, meaning there is only one argument in addition to the program name 
        repeat_alpha(argv[1]); //Print the string to the standard output
    write(1, "\n", 1); //If the number of arguments is not 1, simply display a newline
    return (0);
}

/*
#1  The pre-decrement operator `--n` is used instead of the post-decrement operator `n--`. Both operators decrease the value of n by 1, but 
    the difference lies in the order of operations and the value returned.

    The pre-decrement operator `--n` first decreases the value of `n` and then returns the updated value. 
    
    In contrast, the post-decrement operator `n-- `returns the current value of `n` and then decreases its value.
  */
