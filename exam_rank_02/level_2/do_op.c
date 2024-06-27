/*
Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$
*/

#include <stdio.h> //To call printf()
#include <stdlib.h> //To call atoi()

int do_op(int num1, char op, int num2) //Define a function that takes an integer, a char, and a second integer. This function is to perfom an operation (+, -, /, *, or %) between two numbers
{
    int res; //To store the value/result of the operation 

    if (op == '+') 
        res = num1 + num2;
    else if (op == '-')
        res = num1 - num2;
    else if (op == '*')
        res = num1 * num2;
    else if (op == '/')
        res = num1 / num2;
    else
        res = num1 % num2; //Since the subject.txt implies certainty of no mistakes or extraneous characters in the string, we don't need another if statement for the final operator
    return (res); //Return the result of the arithmetic operation
}

int main(int argc, char **argv)
{
    if (argc == 4) //Perform operations only if argc is four, meaning there needs to be three arguments in addition to the program name
    {
        int res = do_op(atoi(argv[1]), *argv[2], atoi(argv[3])); //Since main() takes in strings as arguments, and do_op() parameters are integers, we need to cast the strings to type `int` using `atoi()`
        printf("%d", res); //Print the result of the arithmetic operation
    }
    printf("\n"); //If the number of parameters is not 3, the program displays a newline
    return (0);
}

//if op == *, do in cml: "*"