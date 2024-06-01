/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
*/

//Second attempt
int    ft_strcmp(char *s1, char *s2)
{
        while (*s1 && *s1 == *s2)
        {
                s2++;
                s1++;
        }
        return (*s1 - *s2);
}

/*
int    ft_strcmp(char *s1, char *s2) //Define a function that takes in two null-terminated strings and compares the two lexicographically. See #1
{
    while (*s1 || *s2) //Loop until either the end of string `s1` or string `s2` is reached
    {
        if (*s1 != *s2) //Checks for a non-matching character in the string
            return (*s1 - *s2); //Return the difference in ASCII values between the two current characters
        s1++; //Move to the next character in the string `s1` for comparison
        s2++; //Move to the next character in the string `s2` for comparison
    }
    return (0);
}


#include <stdio.h>

int main()
{
    char first_str[] = "hello";
    char second_str[] = "hello";

    int result = ft_strcmp(first_str, second_str);
    if (result == 0)
        printf("Strings are equal");
    else
        printf("Strings are unequal");
    printf("\nValue returned by strcmp() is: %d", result);
    return 0;
}

/*
#1  `Lexicographically` means it compares the ASCII values of each character in the two strings.

    `ft_strcmp` returns an integer `greater than`, `equal to`, or `less than 0`, according as the string `s1` is greater than, equal to, or less than the 
    string `s2`.  
    
    It compares the ASCII values of each character in the two strings until a non-matching character or a NULL character is found. 
        - If the first differing character in the first string has a lower ASCII value than the corresponding character in the second string, the function 
          returns a negative number. 
        - If the ASCII value of the first differing character in the first string is greater than the ASCII value of the corresponding character in the 
          second string, the function returns a positive number. 
        - If the two strings are equal up to the end of the shorter string, the function returns `0`
*/
