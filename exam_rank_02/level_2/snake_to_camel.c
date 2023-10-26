/*
Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

Examples:
$>./snake_to_camel "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./snake_to_camel "hello_world" | cat -e
helloWorld$
$>./snake_to_camel | cat -e
$
*/

#include <unistd.h> //To call write()

void    snake_to_camel(char *s) //Define a function that takes a string, converts it into snake_to_camel case in place, and prints it to the STDOUT, therefore returning `void`
{
    while (*s) //Iterate through the string until the end of `s` is reached
    {
        if (*s == '_') //Check if the current character if `s` is a "_"
        {
            s++; //If so, skip the character '_' by moving to the next character
            *s -= 32; //Convert the current character to an uppercase by subtracting `32` from its ASCII value
            write(1, s, 1); //Write the converted character to the STDOUT
        }
        else
            write(1, s, 1); //If not a "_", write the current character of `s` as is to the STDOUT
        s++; //Move to the next character in `s` for processing
    }
}

int main(int argc, char **argv)
{
    if (argc == 2) //Perform operations only if argc is two, meaning there is only one argument in addition to the program name
        snake_to_camel(argv[1]); //Convert every snake_case character into a lowerCamelCase format
    return (0);
}

