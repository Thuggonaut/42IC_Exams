/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
*/

char    *ft_strcpy(char *s1, char *s2) //Define a function that takes two pointers to two strings. `s1` is the destination string where `s2` will be copied into
{
    while (*s2) //This while loop will iterate until the end of the string is reached
        *s1++ = *s2++; //The character pointed to by `s2` is assigned to the memory location pointed to by `s1`, before post incrementing the pointers to move to the next characters
    *s1 = '\0'; //Ensure that the resulting `s1` string is properly terminated, since '\0' is not copied from `s2`
    return (s1); //Return the pointer that points to the copied string
}
