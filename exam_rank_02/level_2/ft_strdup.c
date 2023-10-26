/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/

#include <stdlib.h> //To call malloc(). Also defines `size_t` variable type

size_t ft_strlen(const char *s) //Define a function that takes a pointer to a string, and returns its number of characters up to but not including the null character ('\0')
{
    const char *start; //Declare a pointer variable that will store a pointer pointing to the start of `s` 

    start = s; //Assign to `start` the pointer pointing to `s`
    while (*s++) //This while loop does not need to have any executions inside `{}` brackets. It will loop until the end of `s` is reached, and in each iteration it post-increments the pointer to the next character
      ;
    return (s - start - 1); //`s` is now pointing to the last index of `s`. The resulting length of `s` is calulated by subtracting the final position of `start` of the string (index `0`) from the position of `s`. The `-1` is to account for the extra increment for the `\0`
}

char    *ft_strdup(char *src) //Define a function that takes a null-terminated string that is to be duplicated, and returns a pointer to the newl allocated memory containing a copy of the string
{
    char    *dst; //Declare a pointer that will store the newly allcocated memory
    char    *tmp; //Declare a temporary pointer to iterate through `dst`, and safely copy into `dst` the characters from `src`. See #1
    
    dst = malloc((ft_strlen(src) + 1) * sizeof(dst)); //Allocate memory for the `dst` string using `malloc`. The size of the allocated memory is the length of `src` plus 1 (to accommodate the '\0') multiplied by the size of a char (dst)
    if (!dst)
        return (NULL); //If the memory allocation fails, return `NULL`
    tmp = dst; //Assign the address of `dst` to `tmp`. This is done so that we can modify `tmp` without losing the original address of `dst`
    while (*src) //Loop untill the end of `src` is reached
        *tmp++ = *src++; //For each character iteration in `src`, copy the value from `src` to `tmp`, and increment both `src` and `tmp` to move to the next character of `src` and next index of `tmp` for processing
    *tmp = '\0'; //Add a null terminator at the end of the destination string to ensure the copied string is properly null-terminated
    return (dst); //Return the pointer address of the newly allocated and copied string `dst`
}

/*
int main()
{
    char    *src;
    char    *dst;

    src = "If you don't know, now you know";
    dst = ft_strdup(src);
    printf("Copied: %s\n", dst);
    free(dst);
    return (0);
}

#1  The temporary pointer `tmp` is used to iterate through the `dst` and copy characters from `src`. By using `tmp`, we can safely 
    modify it during the copying process without affecting the original address stored in `dst`. This way, we can return the correct
    starting address of the copied string when the function finishes execution.
        - If we directly modify `dst` while copying characters, we would lose the initial address and would not be able to return it
          correctly.
        - In this case, after the loop is finished, `dst` would point to the end of the copied string rather than the beginning. 
        - Since we've lost the original starting address, we cannot return it as required by the function.
*/