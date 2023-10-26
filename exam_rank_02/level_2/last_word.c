/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

#include <unistd.h> //To call write()

void last_word(const char *s) //Define a function that takes a pointer to a string, and prints the last word of the string
{
    const char *last_space; //Declare `char` pointer variable to store the address of the last space character found in the input string

    last_space = 0; //initialized to `0` (null pointer) to indicate that no `space` or `tab` character has been found yet. See #1
    while (*s) //Loop until the end of `s` is reached
    {        
        if (*s == '\t' || *s == ' ') //Check if the current character of `s` is a `tab` or  `space` character
            last_space = s; //If it is, store the address of the current character in `last_space`, effectively updating the variable to point to the latest `tab` or `space` to be found
        s++; //Move to the next character in `s` for processing
    }
    if (last_space) //Check if `last_space` is not `null`, i.e. atleast one `tab` or `space` was found
    {
        last_space++; //From pointing to the last `tab` or `space` character, increment `last_space` to point to the first character of the last word
        while (*last_space && *last_space != '\t' && *last_space != ' ') //Check that the current character of `s` is not a `\0`, `tab` or `space`
        {
            write(1, last_space, 1); //Write the current character to the stdout
            last_space++; //Move to the next character for processing 
        }
    }
}

int main(int argc, char **argv) //`argv` is a pointer to an array of strings. By using a double pointer `char **argv`, the program can access and retrieve each individual argument as a null-terminated string
{
    if (argc == 2) //Perform operations only if argc is `two`, meaning there is only `one` argument in addition to the program name 
        last_word(argv[1]);
    write(1, "\n", 1);
    return (0);
}

/*
#1  Initializing `last_space` to `0` (null) is a way to represent an empty or uninitialized state for the pointer. 
        - This initialization is essential because, later in the code, the `if (last_space)` condition checks if `last_space` is not `null`, meaning that 
          at least one `space` or `tab` character has been found in the input string.
        - By initializing `last_space` to `0`, we ensure that the condition in the second while loop will only execute if a `space` or `tab` character has 
          been found. If no space or tab character is found in the string, the second loop will not execute, and the function will not print anything.
*/
