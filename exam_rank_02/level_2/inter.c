/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h> //To call write()

void inter(char *s1, char *s2) //Define a helper function that takes in two strings, and writes all the characters, without duplicates, that appear in both the strings, in the order of the first string
{
   char match_count[256] = {0}; //Declare ancharacter array of size `256` and initialize all its elements to `0`. It will be used to store the frequency of each character in `s2`. See #1
   char found[256] = {0}; //Declare acharacter array of size `256` and initialize all its elements to `0`. It will be used to store the characters that have already been found in both strings. See #1

    while (*s2) //Loop until the end of `s2` is reached, and iterate through `s2` to populate the `match_count` array
        match_count[*s2++]++; //For each character in `s2`, increment its corresponding element in the `match_count` array. This will store the frequency of each character in `s2`. See #2
    while (*s1) //Loop until the end of `s1` is reached
    {
        if (match_count[*s1] > 0 && !found[*s1]) //For each character in `s1`, check if it's frequency in `match_count` is > 0 &&  if it hasn't been found already in `found`. If both conditions are true, it means the character is common between `s1` and `s2` and hasn't been printed yet. See #3
        {
            write(1, s1, 1); //Write the current character to the standard output
            found[*s1] = 1; //Access the element at the index corresponding to the ASCII value of the character *s1 in the found array and set the value to `1`, marking it as "found".
            match_count[*s1] = 0; //Reset the frequency count of the current character in `s1` in the `match_count` array to `0`, to prevent duplicate printing. See #4
        }
        s1++; //Move to the next character in `s1` for comparison
    }
}

int main(int argc, char **argv) //`argv` is a pointer to an array of strings. By using a double pointer `char **argv`, the program can access and retrieve each individual argument as a null-terminated string
{
    if (argc == 3) //Perform operations only if argc is three, meaning there needs to be two arguments in addition to the program name
        inter(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}


/*
MY FIRST ATTEMPT: has a helper function `already_found()`

int already_found(char c, char *found) //Define a function that takes in a character, and a string, and checks if the character is already in the string
{
    while (*found) //Loop until the end of the string is reached
    {
        if (*found == c) //Checks if `c` matches the current character in the `found` array
            return (1); //If a match is found, return `1` to indicate it is `true`
        found++; //Move to the next character in `found` for comparison
    }
    return (0); //If no match is found, return `0` to indicate it is `false`
}

void inter(const char *s1, const char *s2) //Define a helper function that takes in two strings, and writes all the characters, without duplicates, that appear in both the strings, in the order of the first string
{
    int match_count[256] = {0}; //Declare an integer array of size `256` and initialize all its elements to `0`. It will be used to store the frequency of each character in `s2`. See #1
    char found[256] = {0}; //Declare a character array of size `256` and initialize all its elements to `0`. It will be used to store the characters that have already been found in both strings. See #1
    char *found_ptr; //Declare a character pointer that will be used to keep track of the next position in the `found` array where a new character can be added
    
    found_ptr = found; //Initialize `found_ptr` to point to the `found` array
    while (*s2)  //Loop until the end of `s2` is reached, and iterate through `s2` to populate the `match_count` array
        match_count[(unsigned char)*s2++]++; //For each character in `s2`, increment its corresponding element in the `match_count` array. This will store the frequency of each character in `s2`. See #2
    while (*s1) //Loop until the end of `s1` is reached
    {
        if (match_count[(unsigned char)*s1] > 0 && !already_found(*s1, found)) //For each character in `s1`, check if it's frequency in `match_count` is > 0 &&  if it hasn't been found already in `found`. If both conditions are true, it means the character is common between `s1` and `s2` and hasn't been printed yet. See #3
        {
            *found_ptr = *s1; //Assign the common character to the `found array` using `found_ptr`
            write(1, found_ptr, 1); //Write it to the standard output
            found_ptr++; //Move the pointer to the next available position in `found`, so the next common character found between the two strings can be stored
            match_count[(unsigned char)*s1] = 0;  //Reset the frequency count of the current character in `s1` in the `match_count` array to `0`. See #4
        }
        s1++; //Move to the next character in `s1` for comparison
    }
}


#1  The size `256` for both the integer and character arrays is chosen because there are 256 possible values for an 8-bit unsigned char. 
        - In C, a `char` is typically represented using 8 bits, which means it can have 2^8 = 256 different values. 
        - By choosing the size `256`, the arrays can accommodate all possible characters in the ASCII table, ranging from `0` to `255`.

    In this code, the arrays `match_count` and `found` are used to store the frequency of characters in `s2` and the characters that have already been found
    in both strings, respectively. 
        - By having an array of size `256`, the code ensures that it can handle any possible ASCII character in the input strings.

    For example: `int match_count[256] = {0};`
        - Is an integer array with `256 elements`, all of which are initialized to `0`. 
        - Each element's index represents an ASCII character. 

    Note for future use: If you don't know the size of the char array at runtime and you don't want to use dynamically allocated memory, you can declare the 
    char array with a fixed maximum size. This maximum size should be large enough to accommodate the largest possible input you expect your program to handle. 
        - Keep in mind that this approach can lead to wasted memory if the actual input size is much smaller than the maximum size.


#2  In the first `while` loop, the line `match_count[(unsigned char)*s2++]++;` is responsible for updating the frequency count of characters in `s2`. 
        - Recall, each element's index of the `match_count` array represents an ASCII character, and the value at that index represents the occurrence count of 
          the character in `s2`.
        - We iterate through `s2` until the end of the string is reached, and at each iteration increment the count at the index corresponding to the ASCII 
          value of the character in the `match_count` array. 
        - For example, the input `s2` = "patdineytoen" will update the `match_count` array as follows:

            match_count['p'] = 1
            match_count['a'] = 1
            match_count['t'] = 2
            match_count['d'] = 1
            match_count['i'] = 1
            match_count['n'] = 2
            match_count['e'] = 2
            match_count['y'] = 1
            match_count['o'] = 1

        - The rest of the elements in the `match_count` array will remain `0` as they are not present in `s2`. The above example representation is a simplified 
          way to show the non-zero elements in the array. In reality, the array will have 256 elements, with most of them set to `0`.

    `match_count[(unsigned char)*s2++]` has two subparts:
        a. `(unsigned char)*s2`: 
            - This part dereferences the pointer `s2` to retrieve the current character in the string `s2` and casts it to an `unsigned char`. 
            - This is done to ensure that the character's ASCII value is used as an index in the `match_count` array.
		            - Characters are represented by their ASCII values, and casting a character to `unsigned char` will give you its unsigned ASCII value, 
                      which can be safely used as an index in the array, as array indices must be non-negative.
	        - To avoid any issues with negative values (as `char` can be signed or unsigned depending on the implementation).
		            - This means that certain character values can be interpreted as negative numbers, which could cause issues when used as an index in 
                      the array. 
		            - By casting the character to `unsigned char`, you ensure that the character's value is always positive and within the range of valid 
                      array indices (0 to 255).
		            - For example, consider a character with the ASCII value of `130`. If `char` is a signed type and represented by an 8-bit value, the 
                      character's value would be interpreted as `-126`. This is because the most significant bit `(MSB)` is used as the `sign bit`, and 
                      when the MSB is set `(1)`, the number is considered negative in two's complement representation (See ##1). Casting the character to 
                      `unsigned char` ensures that the value is treated as `130`, which is a valid index in the `match_count` array. 
    
        b. `s2++` increments the pointer `s2` to point to the next character in the string. 
	        - This is a post-increment operation, meaning the value of `s2` is incremented after the current character is accessed.

        c. `match_count[(unsigned char)*s2++]++` The final part of the expression increments the count of the character in the `match_count` array at the 
            index corresponding to the current character's ASCII value.


#3  The line `(match_count[(unsigned char)*s1] > 0 && !already_found(*s1, found))` checks two things:
        a. `match_count[(unsigned char)*s1] > 0`: 
                - This part checks if the frequency count of the current character in `s1` is greater than `0` in the `match_count` array. 
                - For each character in `s1`, check if its `match_count` is greater than `0` (i.e., it is present in `s2).
		        - To determine whether a character from `s1` is present in `s2`, the code checks the value of `match_count` corresponding to that character. 
                  If the value is greater than 0, it means that the character has been found in `s2`.
		        - The `match_count` array is used to keep track of the count of matching characters between `s1` and `s2`.

        b. `!already_found(*s1, found)`: 
                - This part checks if the current character in `s1` has not already been found in the `found`. 
                - The function returns `true` if the character is already present in the `found` array and `false` otherwise. 
                - The `!` operator negates the result, so the condition becomes `true` if the character is not found in the `found` array.

	    c. If both conditions are met,
		        - the character is added to the `found` array at the position pointed by `found_ptr`, 
		        - the character gets printed, and then 
		        - the `found_ptr` is incremented

            'p': present in 'second' and not in 'found', so add it to 'found' and print it.
            'a': present in 'second' and not in 'found', so add it to 'found' and print it.
            'd': present in 'second' and not in 'found', so add it to 'found' and print it.
            'i': present in 'second' and not in 'found', so add it to 'found' and print it.
            'n': present in 'second' and not in 'found', so add it to 'found' and print it.
            't': present in 'second' and not in 'found', so add it to 'found' and print it.
            'o': present in 'second' and not in 'found', so add it to 'found' and print it.
            'n': already in 'found', so skip it.


#4  The line `match_count[(unsigned char)*s1] = 0;` is responsible for resetting the frequency count of the current character in `s1` in the `match_count`
    array to `0`. 
        - This is done to ensure that the character is not considered again when searching for common characters in the two strings.
        - When you find a common character between the two strings, you store it in the `found` array and then reset its frequency count in the `match_count`
          array. 
        - By setting the frequency count to `0`, you effectively "mark" the character as already found and prevent it from being considered again in the search
          for common characters.


##1 `Two's complement representation` is a method used in digital systems to represent signed integers (both positive and negative numbers) in binary form. 
    It is the most common way of representing signed integers in computers.

    To get the two's complement of a binary number, follow these two steps:
        - Invert all the bits of the given binary number (change 0s to 1s and 1s to 0s).
        - Add 1 to the least significant bit (LSB) of the inverted binary number.

    For example, let's find the two's complement of the binary number 10010:
        - Invert all the bits: 01101
        - Add 1 to the LSB: 01101 + 1 = 01110

    In the two's complement representation, positive integers are represented in the normal binary manner, while negative integers are represented using 
    their two's complement form. 
	    - The most significant bit (MSB) serves as the sign bit: if the MSB is 0, the number is positive; if the MSB is 1, the number is negative.

    One advantage of using two's complement representation is that it allows for simpler arithmetic operations, such as addition and subtraction, as the 
    same rules apply to both positive and negative numbers. 

    Another advantage is that there is only one representation for zero, unlike other signed number representations like one's complement.
*/

/*
MY FIRST ATTEMPT: however is less effiecient due to nested loops.

void inter(const char *s1, const char *s2)
{
    char found[256] = {0};
    char *found_ptr;
	const char *s2_ptr;

	found_ptr = found;
    while (*s1)
    {
        s2_ptr = s2;
        while (*s2_ptr)
        {
            if (*s1 == *s2_ptr && !already_found(*s1, found))
            {
                *found_ptr = *s1;
                write(1, found_ptr, 1);
                found_ptr++;
                break;
            }
            s2_ptr++;
        }
        s1++;
    }
}
*/