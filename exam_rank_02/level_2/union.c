/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/


#include <unistd.h> //To call write()

void ft_union(const char *s1, const char *s2) //Define a function that takes in two strings, and writes to the STDOUT all the characters from either string, in the order of the command line
{
    unsigned char found[256] = {0}; //Declare a character array of size `256` and initialize all its elements to `0`. It will be used to store the characters that have been found in both strings. See #1

    while (*s1) //Loop until the end of `s1` is reached
    {
        if (!found[*s1]) //Access the element at the index corresponding to the ASCII value of the current character in `found` to check if it's not already marked as "found" e.g. it has a value of `1`. The `char` is casted to `int`
        {
            write(1, s1, 1); //Write the current character to the standard output
            found[*s1] = 1; //Access the element at the index corresponding to the ASCII value of the current character in `found` and set the value to `1`, marking it as "found". 
        }
        s1++; //Move to the next character in `s1` for comparison
    }
    while(*s2) //Loop until the end of `s2` is reached
    {
        if (!found[*s2]) //Access the element at the index corresponding to the ASCII value of the current character in `found` to check if it's not already marked as "found" e.g. it has a value of `0` not `1`
        {
            write(1, s2, 1); //Write the current character to the standard output
            found[*s2] = 1; //Access the element at the index corresponding to the ASCII value of the current character in `found` and set the value to `1`, marking it as "found". 
        }
        s2++; //Move to the next character in `s2` for comparison
    }
}

int main(int argc, char **argv) //`argv` is a pointer to an array of strings. By using a double pointer `char **argv`, the program can access and retrieve each individual argument as a null-terminated string
{
    if (argc == 3) //Perform operations only if argc is three, meaning there needs to be two arguments in addition to the program name
        ft_union(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}


/*
MY 2ND ATTEMPT, also works:

void    ft_union(char *s1, char *s2)
{
        char    found[256] = {0};

        while (*s1)
        {
                if (found[*s1] > 0)
                        ;
                else if (found[*s1] == 0)
                {
                        found[*s1]++;
                        write(1, s1, 1);
                }
                s1++;
        }
        while (*s2)
        {
                if (found[*s2] > 0)
                        ;
                else if (found[*s2] == 0)
                {
                        found[*s2]++;
                        write(1, s2, 1);
                }
                s2++;


#1  The size `256` for the character arrays is chosen because there are 256 possible values for an 8-bit unsigned char. 
        - In C, a `char` is typically represented using 8 bits, which means it can have 2^8 = 256 different values. 
        - By choosing the size `256`, the arrays can accommodate all possible characters in the ASCII table, ranging from `0` to `255`.
*/
