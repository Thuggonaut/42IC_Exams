/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
*/

int is_power_of_2(unsigned int n) //Define a function that takes in an unsigned integer (to ensure the input integer is always positive), and returns `1` (true) or `0` (false)
{
    unsigned int i = 1; //Initialise `i` to `1` because any number raised to the power of `0` is equal to `1`, see #1. Must be `unsigned int` as `i` needs to be the same type as `n` for comparison
    while (i < n) //Loop while `i` is less than `n`
        i *= 2; //Iteratively multiply `i` by `2`, effectively checking the next power of `2` until `i` becomes greater than or equal to `n`
    return (i == n); //If `i` is equal to `n` after the loop, it means `n` is a power of `2` (returns `1` for true). If not, it means `n` is not a power of `2` (returns `0` for false).
}

/*
#1  We initialize `i` to `1` because it serves as a starting point for checking if `n` is a power of `2`.
        - By initializing `i` to `1`, we start at the lowest possible power of `2` (2^0 = 1). 
*/

/*
int main()
{
    unsigned int num;

    printf("Enter the number you want to test: ");
    scanf("%u", &num);
    if (is_power_of_2(num) == 1)
        printf("\n%u is a power of 2\n", num);
    else
        printf("\n%u is not a power of 2\n", num);
    return (0);
}
*/
