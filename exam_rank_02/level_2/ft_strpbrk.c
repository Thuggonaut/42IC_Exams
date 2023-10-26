/*
## Subject

```
Assignment name	: ft_strpbrk       
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);
```
*/

#include <stddef.h> //Where the `NULL` macro is defined 

char	*ft_strpbrk(const char *s1, const char *s2) //Define a function that takes two const char * parameters. The const qualifier indicates that the contents of these strings should not be modified within the function
{
    char    *tmp; //Declare a temporary non-const `char *` (because it's what the function returns), that will iterate through `s1` and safely return a non-const pointer. This variable is necessary to avoid directly modifying the const pointer `s1`

    tmp = (char*)s1; //Initialize `tmp` with the address of `s1`. We need to cast the `const char *` pointer `s1` into a non-const pointer type. See #1
    while (*tmp) //Loop until the end of `tmp` is reached, and iterate through the characters of `tmp` (which represents `s1`)
    {
        const char  *set; //Declare a `const char *` variable inside the outer loop. See #2

        set = s2; //Initialize it with the address of `s2`. After the first iteration, if no matching character is found, `set` is reset to point to the begining of `set`, to compare against the next character of `tmp` (which represents `s1`)
        while (*set) //In a nested loop, iterate through the characters of `set` (which represents `s2`) until the end of `set` is reached
        {
            if (*tmp == *set) //Compare the current character of `tmp` with the current character of `set`
                return (tmp); //If they are equal, return the address of the matching character in `tmp`
            set++; //If the characters are not equal, increment the `set` pointer to move to the next character in `s2` for comparison
        }
        tmp++; //If no matching character is found in the current iteration, increment the `tmp` pointer to move to the next character in `s1` for comparison
    }
    return (NULL); //Return NULL to indicate that no match has been found
}

/*
#include <stdio.h>

int main() 
{
    const char s1[] = "examplestring";
    const char s2[] = "!";
    char *result;

    result = ft_strpbrk(s1, s2);
    if (result)
        printf("First matching character: %c\n", *result);
    else 
        printf("Character not found\n");
    return 0;
}


The `strpbrk()` function in C is used to find the first character in a string (s1) that matches any character specified in another 
string (s2). 

It returns a pointer to the character in `s1` that matches one of the characters in `s2`, or `NULL` if no matching character is 
found. 

#1  Casting `s1` to non-const before assigning it to `tmp` does not modify the original `s1` pointer. Instead, it creates a new 
    non-const pointer `tmp` that points to the same memory location as `s1`.

#2  `set` is declared to iterate through the characters of `s2` and safely compare each character with the current character of 
    `tmp` (which represents `s1`). 
        - The purpose of `set` is to keep track of the current position in the `s2` string while searching for a matching character.
        - It is not absolutely necessary to declare the `set` variable, but it helps to make the code more readable and maintainable.
          You could use the `s2` pointer directly in the inner loop, but this would require resetting s2 to its original value after 
          each iteration of the outer loop. This could make the code less readable and more prone to errors.

    The reason `set` is declared within the outer loop is because of its scope and the need to reset its value for each iteration of
    the outer loop. When a variable is declared within a loop, its scope is limited to that loop. By declaring `se`t within the 
    outer loop, it ensures that the value of `set` is reset to the beginning of `s2` for each new character in `tmp` (which represents
    `s1`). This is necessary because we want to compare each character of `s1` with all characters of `s2`.
*/