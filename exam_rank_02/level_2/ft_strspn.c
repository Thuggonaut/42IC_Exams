/*
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);
*/

#include <stdio.h> //Where type `size_t` is defined

size_t ft_strspn(const char *s, const char *accept) //Define a function that takes in two string pointers, `s` and `accept`. The function returns a `size_t` value, which represents the length of the initial segment of `s` that does contains only characters from `accept`
{
    const char *s1; //Declare a pointer variable that will point to the same memory location as the input string `s`. Creating a new pointer means we can safely iterate through the original pointer `s` while preserving it
    const char *accept_ptr; //Declare a pointer variable that will point to the same memory location as the input string `accept`. It will be used to safely iterate through `accept` while preserving it, as opposed to using the original pointer instead
    int         match; //Declare an integer variable to store whether a character from `s` is found in `accept`. Used like a "trigger", set to `1` if true, `0` if false

    s1 = s; //Initialise `s1` to point to the same memory location as the input string
    while (*s1) //Loop until the end of the string `s1` (representing `s`) is reached
    {
        accept_ptr = accept; //Initialise the new pointer variable to point to `accept`, inside the outer loop. See #1
        match = 0; //Initialise `match` to `0` because we havn't found a match yet
        while (*accept_ptr && !match) //Iterate through the characters of `accept_ptr` until the end of `accept_ptr` is reached AND `match` is `0`
            match = (*s1 == *accept_ptr++); //Check if the current character of `s1` is equal to the current character of `accept_ptr`. If so, set `match` to `1` and increment `accept_ptr`. Otherwise, only increment `accept_ptr`. See #2
        if (!match) //Check if match is still `0`
            break ; //If so, break the outer loop, as the current character of `s1` is not found in `accept`
        s1++; //If match is not `0`, increment `s1` to move to the next character in `s` for comparison
    }
    return (s1 - s); //Return the difference between the pointers `s1` and `s`. This represents the length of the initial segment of `s` that contains only characters from `accept`
}


/*
int main(void) 
{
    char string[] = "cabbage";
    int result;

    result = ft_strspn(string, "apc");
    printf("The portion of '%s' containing only a, p, or c is %d bytes long\n", string, result);
    return (0);
}
*/


/*
While `strcspn()` (string complement span) calculates the length of the initial segment of a string that does not contain any characters from a specified 
set of characters, `strspn()` (string span) calculates the length of the initial segment of a string that contains only characters from a specified set of
characters.
    - Note: The first character in `s` must match a character in `accept` for the function to return a non-zero length.


#1  The `accept_ptr` variable has to be initialized inside the outer loop because it's used to iterate through the characters of the `accept` string for 
    each character of the `s1` string. 
        - Initializing `accept_ptr` inside the outer loop ensures that it always starts from the beginning of `accept` for every character of `s1`.

    To break it down step by step, here's what happens in the loops:
        - The outer loop iterates through the characters of `s1` (the main input string).
        - For each character of `s1`, the code needs to check whether it exists in the `accept` string.
        - To perform this check, the inner loop iterates through the characters of `accept` using `accept_ptr`.
        - If the character from `s1` is found in `accept`, the `match` variable is set to `1`, and the inner loop is terminated.
        - If the character from `s1` is not found in `accept`, the `match` variable remains `0`, and the outer loop is terminated.
        - When the outer loop continues with the next character of `s1`, it's necessary to reset `accept_ptr` to the beginning of the accept string to 
          perform the check again.

    By initializing `accept_ptr` inside the outer loop, the inner loop can correctly iterate through the `accept string` for each character of `s1`, 
    allowing the function to determine the length of the initial segment of `s` that contains only characters from `accept`.  


#2  In the line `match = (*s1 == *accept_ptr++);` the following operations are performed:
    - `*s1` dereferences the `s1` pointer, which means it accesses the character that `s1` is pointing to in the string `s`.
    - `*accept_ptr` dereferences the `accept_ptr` pointer, which means it accesses the character that `accept_ptr` is pointing to in the string `accept`.
    - `*s1 == *accept_ptr` checks if the characters pointed by `s1` and `accept_ptr` are equal. 
            - If they are equal, this expression evaluates to `1` (true), otherwise, it evaluates to `0` (false).
    - `accept_ptr++` increments the `accept_ptr` pointer to point to the next character in the string `accept`. 
            - This operation is performed after the comparison between `*s1` and `*accept_ptr` because of the post-increment operator `++`.
    - The result of the comparison (either `1` for true or `0` for false) is assigned to the `match` variable.

    In summary, this line of code compares the characters pointed by `s1` and `accept_ptr`, increments the `accept_ptr` pointer, and stores the result of 
    the comparison in the `matc`h variable. If the characters are equal, match will be set to `1`, otherwise, it will be set to `0`.
*/


/*
First try, but one line too long:

size_t	ft_strspn(const char *s, const char *accept) 
{
    size_t      count;
    const char  *s1;

    count = 0;
    s1 = s;
    while (*s1)
    {
        const char *accept_ptr;

        accept_ptr = accept;
        while (*accept_ptr)
        {
            if (*s == *accept_ptr)
            {
                count++;
                break ;
            }
            accept_ptr++;
        }
        if (*accept_ptr == '\0')
            return (count);
        s++;
    }
    return (count);
}
*/