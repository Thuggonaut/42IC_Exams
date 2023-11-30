/*
Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>
*/

#include <unistd.h> //To call write()

 void   expand_str(char *s) //Define a function that takes in a string, writes the words contained in the string with three spaces between them. Returns void because it performs an operation and does not return a value
 {
    int     in_word; //Declare a variable to be used as a flag to handle when a `space` should be printed

    while(*s) //Loop until the end of the input string is reached
    {
        if (*s == ' ' || *s == '\t') //Check if the current character is a delimiter
        {
            if (in_word == 1 && (*(s + 1) != ' ' && *(s + 1) != '\t' && *(s + 1) != '\0')) //Check if we are inside a word, and if the next character is not a delimiter or the end of a string. See #1
            {
                write(1, "   ", 3); //If so, three `space` is printed
                in_word = 0; //Reset the flag to `0` to tell the next iteration, that if the next character is a delimiter, do not print a space
            }
        }
        else //If the current character is not a delimiter
        {
            write(1, s, 1); //Print the current character, which will be a part of a word in the input string
            in_word = 1; //Set the flag to `1`, to tell the next iteration, that if a dilimiter is found before the next word, print the `spaces`
        }
        s++; //Move to the next character for processing
    }
 }

int main(int argc, char **argv) //`argv` is a pointer to an array of strings. By using a double pointer `char **argv`, the program can access and retrieve each individual argument as a null-terminated string
{
    if (argc == 2) //Perform operations only if argc is `two`, meaning there is only `one` argument in addition to the program name 
        expand_str(argv[1]);
    write(1, "\n", 1);
    return (0);
}

/*
2ND ATTEMPT, ALSO WORKS:

void    expand_str(char *s)
{
        int     first = 0;

        while (*s == ' ' || *s == '\t')
                s++;
        while (*s)
        {
                if (first == 1 && *s != ' ' && *s != '\t' && (*(s - 1) == ' ' || *(s - 1) == '\t'))
                {
                        write(1, "   ", 3);
                        write(1, s, 1);
                }
                else if (*s != ' ' && *s != '\t')
                {
                        write(1, s, 1);
                        first = 1;
                }
                s++;
        }
}
*/

/*
If the next character is not a space, not a tab, and not the end of the string, the code will print three spaces. 
	- This condition ensures that only when the next character is a part of a word and not a delimiter, the three spaces will be printed.
	- In other words, after every word, it will skip every delimiter until it finds the dilimeter before the next word, after which it will 
	  print the three spaces. 

Example: *str = "Hi     there  . " (5, 2, 1 spaces between the words)

1. Initially, the `in_word flag` is set to 0 because we haven't encountered any word yet. 
	- The string *str is pointing to the beginning of the input string: "H"
	- The code checks if the current character, "H", is a space or tab. Since it's not, it writes the character to the output
	- `in_word` is set to 1.
	- Output: "H"

2. The next character is "i", which is not a space or tab. It's part of the word, so it's written to the output
	- `in_word` remains 1.
	- Output: "Hi"

3. The next character is a space, " ". `in_word` is 1, but the following character is also a space, so the if condition is not met, and it goes to `s++`
	- Output: "Hi"

4. The code continues to the next character, which is a second space, " ". 
	- The if condition is skipped because the next character is also a space.
	- Output: "Hi"
	- This is repeated for another few iterations until the if condition is met.

5. The code encounters a 5th space, " ", but this time, the following character is not a dilimiter and not the end of a string, signifying there's a next word.
	- The if condition is met, and three spaces are printed.
	- Output: "Hi   "
	
6. Now, we come across the word "there" in the input. The code writes it to the output.
	- `in_word` is set to 1.
	- Output: "Hi   there"

7. The code encounters a space, " ". `in_word` is 1, but the following character is also a space, so the if condition is not met, and it goes to `s++`
	- Output: "Hi   there"
	- The second space it encounters meets the if condition because its following character is a ".". 
	- Output: "Hi   there   "

8. Finally, the code encounters a period, ".".
	- Output: "Hi   there   ."

9. The string ends, so the loop exits.
*/