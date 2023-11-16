/*
## Subject

```
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$

```
*/

#include <unistd.h> //To call write()

int ft_strlen(char *s) //Define a function that takes a pointer to a string, and returns its number of characters up to but not including the null character ('\0')
{
    char *start; //Declare a pointer variable that will store a pointer pointing to the start of `s` 

    start = s; //Assign to `start` the pointer pointing to `s`
    while (*s++) //This while loop does not need to have any executions inside `{}` brackets. It will loop until the end of `s` is reached, and in each iteration it post-increments the pointer to the next character
        ;
    return (s - start - 1); //`s` is now pointing to the last index of `s`. The resulting length of `s` is calulated by subtracting the final position of `start` of the string (index `0`) from the position of `s`. The `-1` is to account for the extra increment for the `\0`
}

void    rev_print(char *s)
{
    int  len; //To store the length of the string

    len = ft_strlen(s); //Calculate the length of the string
    while (len-- > 0) //Loop as many times as the number of characters in the string. `len--` because, '\0' is at s[len]
        write(1, &s[len], 1); //Write to the standard output, in reverse order, the current character of the string, starting from the last character
}

int main(int argc, char **argv) //argv is a pointer to an array of strings. By using a double pointer char **argv, the program can access and retrieve each individual argument as a null-terminated string
{
    if (argc == 2) //Perform operations only if argc is two, meaning there is only one argument in addition to the program name 
        rev_print(argv[1]);
    write(1, "\n", 1);
    return (0);
}
