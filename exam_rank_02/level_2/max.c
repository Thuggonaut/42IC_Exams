/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

int max(int *tab, unsigned int len) //Define a function that takes in a integer array, and the length of the integer array
{
    unsigned int    i; //Declare an `unsigned int` variable to store the index of the integer array during the iterations. Must be `unsigned int` type, the same as the type of `len` for comparison to work
    int             max; //Declare an integer variable to store the largest number found in the array

    i = 0; //Initialise to `0` to start iterating from the first index of the integer array
    max = 0; //Initialise to `0` because we haven't found the largest number yet
    while (i < len) //Loop and Iterate through the array until the end of the array is reached. Recall, `i` starts as index `0`
    {
        if (tab[i] > max) //Check if the current integer is larger than `max`
            max = tab[i]; //If so, update `max` to store the larger number
        i++; //Move to the next integer in the array for comparison
    }
    return (max); //Return the largest integer found
}

/*
int main()
{
    int tab[] = {0, 1, 2, 10};
    int result = max(tab, 4);
    printf("%d\n", result);
    return (0);
}
*/