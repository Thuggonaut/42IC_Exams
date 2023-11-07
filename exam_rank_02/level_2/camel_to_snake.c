/*
Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
*/

#include <unistd.h> //To call write()

void    camel_to_snake(char *s) //Define a function that takes a pointer to a string. Type `void` because it performs an operation and does not return a value
{
    while (*s) //Loop until the end of the string is reached
    {
        if (*s >= 'A' && *s <= 'Z') //Checks if the current character is an uppercase character
        {
            *s += 32; //Convert the uppercase character to a lowercase character
            write(1, "_", 1); //Print a "_" to the standard output. Note, a "_" will never be printed at index [0] because lowerCamelCase begins with a lowercase 
        }                     //The "_" needs to be printed before the converted character is printed
        write(1, s++, 1); //Prints either the converted character pointed to by `s`, or, if the current character was not uppercase, prints the character as is, before moving to the next character
    }
}

int main(int argc, char **argv)
{
    if (argc == 2) //Perform operations only if argc is two, meaning there is only one argument in addition to the program name
        camel_to_snake(argv[1]); //Convert every lowerCamelCase character into a snake_case format
    return (0);
}
