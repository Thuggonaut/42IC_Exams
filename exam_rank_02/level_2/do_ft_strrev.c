/*
## Subject

```
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);

```
*/

#include <stdio.h>
/*
size_t ft_strlen(const char *s) //Define a function that takes a pointer to a string, and returns its number of characters up to but not including the null character ('\0')
{
    const char *start; //Declare a pointer variable that will store a pointer pointing to the start of `s` 

    start = s; //Assign to `start` the pointer pointing to `s`
    while (*s++) //This while loop does not need to have any executions inside `{}` brackets. It will loop until the end of `s` is reached, and in each iteration it post-increments the pointer to the next character
      ;
    return (s - start - 1); //`s` is now pointing to the last index of `s`. The resulting length of `s` is calulated by subtracting the final position of `start` of the string (index `0`) from the position of `s`. The `-1` is to account for the extra increment for the `\0`
}

char *ft_strrev(char *s) //Define a function that takes a pointer to a string, reverses the string in place, and returns a pointer to the reversed string
{
    char *start; //Declare a pointer variable that will store a pointer to the begining of the input string
    char *end; //Declare a pointer variable that will store a pointer to the last character of the input string

    start = s; //`start` is initialized to point to the beginning of the input string `s`
    end = s + ft_strlen(s) - 1; //`end` is initialized to point to the last character of the input string `s`, which is calculated by adding the length of `s` (minus 1) to the starting pointer. See #1
    while (start < end) //Loop until the `start` pointer is greater than or equal to the `end` pointer. The while loop is used to swap the characters at the `start` and `end` pointers. See #2
    {
        char temp; //Declare a temporary character variable that will store the character at the start pointer
        
        temp = *start; //`temp` is initialized to point to the character at the start pointer (representing the beginning of the input string `s`)
        *start = *end; //The character at the `end` pointer is assigned to the `start` pointer
        *end = temp; //The character stored in `temp` is assigned to the `end` pointer
        start++; //Incrementing the start pointer moves it to the next character in the string. See #3
        end--; //Decrementing the end pointer moves it to the previous character in the string. See #3
    }
    return (s); //A pointer to the reversed string is returned
}


2ND ATTEMPT, ALSO WORKS:
*/
char *ft_strrev(char *str)
{
	char 	*start = str;
	char 	*end = str;
	char	temp;

	while (*end)
		end++;
	end--; // Move end to the last character (not null terminator)

	while (start < end)
	{
		temp = *end;
		*end = *start;
		*start = temp;
		start++;
		end--;;
	}
	return (str);
}

/*
int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s\n", ft_strrev(argv[1]));
	return (0);
}*/

/*
#1  `str + ft_strlen(str) - 1` calculates the memory address of the last character in the string, and is then used to initialize the `end` pointer to point 
    to the last character of the input string `str`.
        - `str` is a pointer pointing to the first character of the string.
        - `ft_strlen(str)` returns the length of the string. Note that the length does not include the null terminator at the end of the string.
        - `str + ft_strlen(str)` expression adds the length of the string to the starting address of the string. 
                - Since pointer arithmetic is used here, this results in a pointer that points to the memory location right after the last character of the
                  string (i.e., the null terminator).
                - So, it translates to (pointer position) + (len) = (pointer position) moved (len) positions).
                - Suppose we have *str = "12345". 
                        - This translates to (str[0]) + (5) = (str[5])
                        - (str[5]) = '\0'
        - Subtracting `1` from the pointer pointing to the null terminator brings it back to the last character of the string (i.e. str[4] = '5'). 
                - This is the final value assigned to the `end` pointer.


#2  When the `start` pointer reaches or surpasses the `end` pointer, it indicates that the pointers have already met or crossed each other, and all the 
    characters in the string have been swapped.
        - This is because `start` initially points to the first character of the string, and `end` initially points to the last character. 
        - As the `start` pointer is incremented and the `end` pointer is decremented, they move towards each other.
                - Using our previous example, *str = "12345"
                        - Step 1:
                          temp = start[0](1) = '1'
                          start[0](1) = end[4](5) = '5'
                          end[4](5) = temp = '1'
                        - Step2:
                          Increment `start` = start[1](2) = '2'
                          Decrement `end` = end[3](4) = '4'
                        - Step 3:
                          temp = start[1](2) = '2'
                          start[1](2) = end[3](4) = '4'
                          end[3](4) = temp = '2'
                        - Step 4:
                          Increment `start` = start[2]
                          Decrement `end` = end[2]
                        - At this point the `start` and `end` pointers are equal, indicating all the numbers have been swapped, and at index[2] is '3'
                          which does not need to be swapped.
                        - Suppose we had a string of "123456" instead. Before the loop exits, it does a final swap:
                                - start[2](3) and end[3](4) would be swapped into
                                - start[2](4) and end[3](3)
                                - Incrementing `start` = start[3]
                                - Decrementing `end` = end[2]
                                - `start` is now greater than `end` and the loop exits accordingly                                             


#3  The `start` pointer is incremented, and the `end` pointer is decremented to move the pointers towards each other. This is done to reverse the string 
    in place by swapping the characters at the `start` and `end` pointers until they meet or cross each other.
        - The loop continues until the `start` pointer is greater than or equal to the `end` pointer, at which point the entire string has been reversed.
        - The increment and decrement operations on pointers are based on the size of the data type the pointer is pointing to. In this case, the pointers
          are of type `char`, so incrementing `start` moves it to the next character in memory, and decrementing `end` moves it to the previous character 
          in memory.
*/