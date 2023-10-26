/*
Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
*/

#include <unistd.h>

void wdmatch(char *s1, char *s2) //Define a function that takes two strings, and prints the first string if all it's letters are contained in the second string, in the order of the second string
{
    char* str1; //Declare a char pointer variable to point to `s1` and safely iterate through it without risking modifying the input string
    char* str2; //Declare a char pointer variable to point to `s2` and safely iterate through it without risking modifying the input string

    str1 = s1; //`str1` now points to the input string `s1` for safe processing
    str2 = s2; //`str2` now points to the input string `s2` for safe processing
    while (*str1) //Loop until the end of the string is reached
    {
        while (*str2 != *str1 && *str2) //Check if the current character of `str2` does not match the current character of `str1`, && the end of `str2` is not reached. This is essentially searching through `s2` for the current character from `s1`
            str2++; //Move to the next character in `str2` to search if it exists in `str1`
        if (!*str2) //Checks if the current character from `s1` was not found in `s2`. `str2` is now pointing to the null character
            return ; //The function returns immediately
        str1++; //If the current character from `s1` was found in `str`2, both `str1` and `str2` are incremented to point to the next characters
        str2++;
    }
    write(1, s1, str1 - s1); //If all characters in `s1` have been found in `s2` in the same order, write the part of `s1` that matches `s2` to the STDOUT. See #1
}

int main(int argc, char **argv) //`argv` is a pointer to an array of strings. By using a double pointer `char **argv`, the program can access and retrieve each individual argument as a null-terminated string
{
    if (argc == 3) //Perform operations only if argc is three, meaning there needs to be two arguments in addition to the program name
        wdmatch(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}


/*
#1  The length of the output is calculated as the difference between the memory addresses `str1` and `s1` are pointing to, which gives the number of 
    characters in `s1` that were found in `s2`.
        - Recall, write() prototype is `write(fd, buffer, sizeof(buffer)).

    1. Suppose we have a string "abc". In memory, it might look something like this:

        Memory Address:  1000  1001  1002  1003
        Value:           'a'   'b'   'c'   '\0'

    2. Now, let's say `s1` is a pointer to the start of this string. So, `s1` would be pointing to the memory address 1000:

        s1
        ↓
        'a'   'b'   'c'   '\0'

   3.  We also have `str1`, which starts at the same place as `s1` but moves through the string as we process each character. 
       After we've processed the entire string, `str1` would be pointing to the null character at the end:

        s1            str1
        ↓              ↓
        'a'   'b'   'c'   '\0'

    4. Now, when we do `str1 - s1`, we're calculating the difference between the memory addresses that `str1` and `str1` are pointing to. 
       In this case, that's `1003 - 1000`, which equals ``3. This is the length of the string "abc".


MY FIRST ATTEMPT: does not respect the order of the second string as required by assignment

void    wdmatch(const char *s1, const char *s2)
{
    unsigned char   found[256] = {0}; //Declare an `unsigned char` array with `256` elements (to represent all possible characters from the ASCII table), to store characters found
    const char      *s1_cpy;
    int             all_found;

    s1_cpy = s1;
    all_found = 1;
    while (*s2) ////Loop until the end of `s2` and iterate through `s2` to populate the `found` array
        found[*s2++]++;
    while (*s1) //Iterate through `s1` and check if the characters have been found in `found`
    {
        if (found[*s1])
            s1++;
        else
            all_found = 0;
    }
    if (all_found == 1) //If all are found, print `s1`
    {
        while (*s1_cpy)
            write(1, s1_cpy++, 1);
    }
}

#1  The size `256` for the integer array is chosen because there are 256 possible values for an 8-bit unsigned char. 
        - In C, a `char` is typically represented using 8 bits, which means it can have 2^8 = 256 different values. 
        - By choosing the size `256`, the arrays can accommodate all possible characters in the ASCII table, ranging from `0` to `255`.
*/
