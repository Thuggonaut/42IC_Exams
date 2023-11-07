/*
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
*/

#include <unistd.h> //To call write()

void    alpha_mirror(char *s) //Define a function that takes a pointer to a string. Type `void` because it performs an operation and does not return a value
{
    int i; //To be used as a loop counter
    char *min; //A pointer to a character arrays that will store the lower and uppercase characters of 'a, A' to 'm, M', used for mapping
    char *max; //A pointer to a character arrays that will store the lower and uppercase characters of 'z, Z' to 'n, N', used for mapping

    min = "abcdefghijklmABCDEFGHIJKLM"; //Assign to `min` the respective set of alphabets to the min pointers. The min array represents the original alphabets
    max = "zyxwvutsrqponZYXWVUTSRQPON"; //Assign to `max` the respective set of alphabets to the max pointers. The max array represents the mirrored alphabets
    while (*s) //Loop until the end of the string is reached
    {
        i = 0; 
        while (i < 26) //`26` and not `27` because an array index starts at `0`
        {
            if (*s == min[i]) //If the current character matches `a, A` to `m, M`
                *s = max[i]; //Mirror the character
            else if (*s == max[i]) //If the current character matches `z, Z` to `n, N`
                *s = min[i]; //Undo the mirror effect
            i++; //Move to the next character of the `min` an `max` arrays to search for the next match of the current string character
        }
        write(1, s++, 1); //Writes the current character pointed to by `s` to the standard output then move to the next character of the string for processing
    }
}

int main(int argc, char **argv) //`argv` is a pointer to an array of strings. By using a double pointer `char **argv`, the program can access and retrieve each individual argument as a null-terminated string
{
    if (argc == 2) //Perform operations only if argc is two, meaning there is only one argument in addition to the program name
        alpha_mirror(argv[1]); //Perform operations only if argc is two, meaning there is only one argument in addition to the program name 
    write(1, "\n", 1);
    return 0;
}
