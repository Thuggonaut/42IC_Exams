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
MY FIRST ATTEMPT:

int already_found(char c, char *found) //Define a function that takes in a character, and a string, and checks if the character is already in the string
{
    while (*found) //Loop until the end of the string is reached
    {
        if (*found == c) //Checks if `c` matches the current character in the `found` array
            return (1); //If a match is found, return `1` to indicate it is `true`
        found++; //Move to the next character in `found` for comparison
    }
    return (0); //If no match is found, return `0` to indicate it is `false`
}

void    union_c(const char *s1, const char *s2)
{
    char found[256] = {0}; //Declare a character array of size `256` and initialize all its elements to `0`. It will be used to store the characters that have been found in both strings. See #1
    char *found_ptr; //Declare a character pointer that will be used to keep track of the next position in the `found` array where a new character can be added
    
    found_ptr = found; //Initialize `found_ptr` to point to the `found` array
    while (*s1) //Loop until the end of `s1` is reached
    {
        if (!already_found(*s1, found)) //For each character in `s1`, check if it hasn't been found already in `found`
        {
            *found_ptr = *s1; //Assign the common character to the `found array` using `found_ptr`
            write(1, found_ptr, 1); //Write it to the standard output
            found_ptr++; //Move the pointer to the next available position in `found`, so the next common character found between the two strings can be stored
        }
        s1++; //Move to the next character in `s1` for comparison
    }
    while(*s2) //Loop until the end of `s2` is reached
    {
        if (!already_found(*s2, found)) //For each character in `s2`, check if it hasn't been found already in `found`
        {
            *found_ptr = *s2; //Assign the common character to the `found array` using `found_ptr`
            write(1, found_ptr, 1); //Write it to the standard output
            found_ptr++; //Move the pointer to the next available position in `found`, so the next common character found between the two strings can be stored
        }
        s2++; //Move to the next character in `s2` for comparison
    }
}

#1  The size `256` for the character arrays is chosen because there are 256 possible values for an 8-bit unsigned char. 
        - In C, a `char` is typically represented using 8 bits, which means it can have 2^8 = 256 different values. 
        - By choosing the size `256`, the arrays can accommodate all possible characters in the ASCII table, ranging from `0` to `255`.
*/
