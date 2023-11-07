/*
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);
*/

void	ft_swap(int *a, int *b) //Define a function that takes two integer pointers, which are used to access the values of the variables that need to be swapped. Type `void` because it performs an operation and does not return a value
{
    int temp; //Define an integer variable to temporarily store a value, to prevent losing data during swapping

    temp = *a; //Temporarily store the value of *a while swapping the values
    *a = *b;
    *b = temp;
}

/*
#include <stdio.h>

int     main(void)
{
        int     a = 2;
        int     b = 1;

        printf("Before swap: a = %d and b = %d\n", a, b);
        ft_swap(&a, &b);
        printf("After swap: a = %d and b = %d\n", a, b);
        return (0);
}*/