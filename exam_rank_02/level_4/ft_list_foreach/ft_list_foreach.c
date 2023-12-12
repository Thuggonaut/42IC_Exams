/*
Assignment name  : ft_list_foreach
Expected files   : ft_list_foreach.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a list and a function pointer, and applies this
function to each element of the list.

It must be declared as follows:

void	ft_list_foreach(t_list *begin_list, void (*f)(void *));

The function pointed to by f will be used as follows:

(*f)(list_ptr->data);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct	s_list
{
	struct s_list *next;
	void		  *data;
}				 t_list;
*/

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*current = begin_list;

	while (current)
	{
		(*f)(current->data);
		current = current->next;
	}
}

/*
#include <stdio.h>
#include <stdlib.h>

//Define a simple function that prints the data of each element
void print_data(void *data)
{
	printf("%s\n", (char *)data);
}

int		main(void)
{
	//Create a linked list with some data
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->data = "Hello";
	node1->next = node2;

	node2->data = "World";
	node2->next = node3;

	node3->data = "!";
	node3->next = NULL;

	//Call ft_list_foreach with the head node, to apply print_data to each element
	ft_list_foreach(node1, print_data);

	//Free the allocated memory
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
*/