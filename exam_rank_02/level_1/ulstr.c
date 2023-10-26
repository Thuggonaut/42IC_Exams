/*
Assignment name  : ulstr
Expected files   : ulstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'.

Examples :

$>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.$
$>./ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  $
$>./ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
$>./ulstr | cat -e
$
*/

#include <unistd.h> //To call write()

void    ulstr(char *s) //Define a function that takes a pointer to a string. Type `void` because it performs an operation and does not return a value
{
    char c; //`c` is declared, for the processing of each character in the string. See #1
    
    while (*s) //Loop until the end of the string is reached
    {
        c = *s; //The current character is assigned to `c`
        if (c >= 'a' && c <= 'z') //Checks for a lowercase alphabet character
		    c -= 32; //If lowercase, convert to uppercase using ASCII values
        else if (c >= 'A' && c <= 'Z') //Checks for an uppercase alphabet character
		    c += 32; //If uppercase, convert to lowercase using ASCII values
	    write(1, &c, 1); //Write to the standard output, the case-converted alphabet character, or, the non-alphabet character
        s++; //Move to the next character of the string
    }
}

int main(int argc, char **argv) //argv is a pointer to an array of strings. By using a double pointer char **argv, the program can access and retrieve each individual argument as a null-terminated string
{
    if (argc == 2) //Perform operations only if argc is two, meaning there is only one argument in addition to the program name 
        ulstr(argv[1]); //Reverse the case of all the characters in the string
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

