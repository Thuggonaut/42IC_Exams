/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
*/

#include <stdio.h>
#include <string.h>

size_t ft_strcspn(const char *s, const char *reject) //Define a function thhat takes in two string pointers, `s` and `reject`. The function returns a `size_t` value, which represents the length of the initial segment of `s` that does not contain any character from `reject`
{
    size_t count; //Declare a variable of type `size_t` (because that's what the function returns), to keep track of the number of characters trraversed in `s` before any character from `reject` is found
    const char *reject_ptr; //Declare a pointer that points to the beginning of `reject`. 

    count = 0; 
    while (*s) //Loop until the end of string `s` is reached
    {
        reject_ptr = reject; //Initialise `reject_ptr inside the outer loop. See #1. This pointer will be used to iterate through the characters in `reject`. See #2
        while (*reject_ptr) //Loop in a nested while loop until the end of the string `reject` is reached
        {
            if (*s == *reject_ptr) //Compare the current character in `s` with the current character in `reject`. If they are equal, return the current value of `count`
                return (count);
            reject_ptr++; //If the current characters in `s` and `reject` are not equal, increment the `reject_ptr` to move to the next character in `reject`
        }
        count++; //After the inner loop completes (i.e., all characters in `reject` have been compared to the current character in `s`), increment `count`
        s++; //Move to the next character in `s` for comparison
    }
    return (count); //If the outer loop completes (i.e., all characters in `s` have been checked), return the final value of `count`
}


/*
int main()
{
    int size;

    char str1[] = "geeksforgeeks";
    char str2[] = "zfc";
    size = ft_strcspn(str1, str2);
    printf("The unmatched characters before first matched character :  %d\n", size);
    return (0);
}


While `strspn()` (string span) calculates the length of the initial segment of a string that contains only characters from a specified set of characters, 
`strcspn()` (string complement span) calculates the length of the initial segment of a string that does not contain any characters from a specified set 
of characters.


`strcspn()` calculates the length of the initial segment of a string, which consists entirely of characters not in another specified string.

The name "strcspn" stands for "string complementary span" because it searches for characters not found in the second string, which is the 
compliment of the second string.

The syntax is:

    size_t  strcspn(const char *s1, const char *s2);

        - `s1` is the target string in which the search has to be made
        - `s2` is the argument string containing characters to match in the target string
    
`strcspn()` returns the number of characters before the 1st occurrence of a character present in both strings.


#1  Initialising the pointer `reject_ptr` inside the outer loop is necessary because you want to reset the pointer to the beginning of `reject`
    for each character in `s`. 
        - If you initialised `reject_ptr` outside the outer loop, it would not be reset to the beginning of `eject` in each iteration of the outer
          loop, which would lead to incorrect results.

    By initialising `reject_ptr` inside the outer loop, you ensure that it points to the beginning of `reject` each time the loop iterates over a 
    new character in `s`. 
        - This allows you to compare each character in `s` with all the characters in `reject`.

    In this code above, `reject_ptr` is initialized to point to the beginning of `reject` for each character in `s`, ensuring that all necessary 
    comparisons are made to determine the length of the initial segment of `s` that does not contain any character from `reject`.


#2  We need to create a pointer to iterate through the string `reject` for comparison and memory access while preserving the original pointer for 
    future use. 
        - Iteration: 
          The pointer allows you to iterate through the characters in `reject` using pointer arithmetic. You can increment the pointer to move 
          from one character to another without needing an additional index variable. This is a more efficient way to traverse the string.
        - Comparison: 
          By dereferencing the pointer, you can access the current character in `reject` and compare it with the current character in `s` The 
          dereference operator `*` is used to get the value stored at the memory location pointed to by the pointer.
        - Memory Access: 
          Pointers allow you to access the memory location of the character array directly. This can lead to more efficient code and better 
          performance, especially when working with large data structures or low-level programming tasks.
        - Preserving the original pointer: 
          Using a separate pointer (reject_ptr) for iterating through `reject` ensures that the original `reject` pointer remains unchanged. This
          is useful if you need to refer back to the original pointer later in the code or if you want to avoid side effects caused by modifying 
          the original pointer.

    If we didn't create a pointer to point to `reject`, we'd have to use another approach, such as `indices` and a `strlen()` function. However 
    calling `strlen()` repeatedly in the loop can add extra overhead, and using indices may be less efficient than using pointer arithmetic for 
    character iteration. By using a pointer, you can directly access and manipulate the memory addresses of the characters, leading to more 
    efficient code execution.
*/