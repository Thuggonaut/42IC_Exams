/*
Assignment name  : flood_fill
Expected files   : *.c, *.h
Allowed functions: -
--------------------------------------------------------------------------------

Write a function that takes a char ** as a 2-dimensional array of char, a
t_point as the dimensions of this array and a t_point as the starting point.

Starting from the given 'begin' t_point, this function fills an entire zone
by replacing characters inside with the character 'F'. A zone is an group of
the same character delimitated horizontally and vertically by other characters
or the array boundry.

The flood_fill function won't fill diagonally.

The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);

The t_point structure is prototyped like this:

  typedef struct  s_point
  {
	int		   x;
	int		   y;
  }			   t_point;

Example:

$> cat test.c
#include <stdlib.h>
#include <stdio.h>
#include "flood_fill.h"

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

$> gcc flood_fill.c test.c -o test; ./test
11111111
10001001
10010001
10110001
11100001

FFFFFFFF
F000F00F
F00F000F
F0FF000F
FFF0000F
$>
*/

#include "flood_fill.h"

//Define a recursive function that starts at point `begin`, replacing connected characters the same as the starting point with 'F'
//`tab` points to a 2D array of characters
//`size` represents the dimensions of the array
//`begin` represents the starting point
void	flood_fill(char **tab, t_point size, t_point begin) 
{
	//Declare a variable and assign it the value of the character at point `begin` in the array `tab`
	//This character is the one that will be replaced by 'F' during the flood fill
	//See #1 re order of y(row) vs x(column)
	char	target = tab[begin.y][begin.x];

	//Declare a helper function fill that takes x and y points. It will recursively fill the (x, y) region with `F`
	void	fill(int x, int y) 
	{
		//Check if the current position (x, y) is within the bounds of the array and if the character at that position is equal to the target character. See #2
		if (x >= 0 && x < size.x && y >= 0 && y < size.y && tab[y][x] == target) 
		{
			tab[y][x] = 'F'; //Replace the character at position (x, y) in the array with `F`
			fill(x + 1, y); //Recursively call `fill` for the position to the right of the current position (x, y)
			fill(x - 1, y); //Recursively call `fill` for the position to the left of the current position (x, y)
			fill(x, y + 1); //Recursively call `fill` for the position for the position below the current position (x, y)
			fill(x, y - 1); //Recursively call `fill` for the position for the position above the current position (x, y)
		}
	}
	fill(begin.x, begin.y);
}
/*
#include <stdlib.h>
#include <stdio.h>

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int		main(void)
{
	t_point		size = {4, 3};
	char		*zone[] = 
	{
		"1111",
		"1001",
		"1011",
	};

	char**		area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point		begin = {0, 0};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}*/

/*
#1	In C programming, arrays are stored in a row-major order, meaning that elements in the same row are stored next to each other in memory. 
	So, when you access tab[y][x], you are navigating to the y-th row and then accessing the x-th element in that row.

	For a 2D array in C, it's crucial to use the correct order of indices (tab[y][x]), where the first index refers to the row and the second 
	index refers to the column. Interchanging them (tab[x][y]) can lead to memory access errors.


#2	This line `if (x >= 0 && x < size.x && y >= 0 && y < size.y && tab[y][x] == target)`:
		- `x >= 0` checks if the current position is not to the left of the array; 
		- `x < size.x` checks if the x-coordinate is less than the width of the array;
		-  `y >= 0` checks if the current position is not above the array;
		- `y < size.y` checks if the y-coordinate is less than the height of the array;
		- `tab[y][x] == target` checks if the character at the current position (x, y) in the array `tab` is equal to the target character
*/