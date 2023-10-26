/*
Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
*/

#include <unistd.h> //To call write()

void    rotone(char *s) //Define a function that takes a pointer to a string. Type `void` because it performs an operation and does not return a value
{
    char c; //`c` is declared, for the processing of each character in the string. See #1
    
    while (*s) //Loop until the end of the string is reached
    {
        c = *s; //The current character is assigned to `c`
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) //Checks if the current character is an alphabet lowercase or uppercase
        {
            if (c == 'z') //Checks for 'z'(ASCII 90), in which case, convert to 'a'(ASCII 65)
                c = 'a';
            else if (c == 'Z') //Checks for 'Z'(ASCII 122), in which case, convert to 'A'(ASCII 97)
                c = 'A';
            else 
                c++; //If not 'z' or 'Z', simply convert `c` into the next corresponding letter (rotate by 1) 
        }
        write(1, &c, 1); //Write the current character to the standard output
        s++; //Move to the nect character for processing
    }
}

int main(int argc, char **argv) //argv is a pointer to an array of strings. By using a double pointer char **argv, the program can access and retrieve each individual argument as a null-terminated string
{    
    if (argc == 2) //Perform operations only if argc is two, meaning there is only one argument in addition to the program name 
        rotone(argv[1]); //Rotate every character in the input string, by one ASCII value
    write(1, "\n", 1);
    return (0);
}

/*
#1	The `char c` is used as a temporary variable to hold the current character being processed from the string. This is done for a couple of reasons:
		- It allows you to modify the character (change its case) without affecting the original string. This is important if you want to keep the 
  		  original string unchanged, which is often the case in C programming.
		- It simplifies the code by avoiding repeated dereferencing of the pointer `str`. Instead of writing *str multiple times in the code, you 
                  can just use `c`.
*/
