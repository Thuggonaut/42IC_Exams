/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct	  s_list
{
	struct s_list   *next;
	void			*data;
}				   t_list;
$>
*/

#include <stdlib.h>

typedef struct	  s_list
{
	struct s_list   *next;
	void			*data;
}				   t_list;

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current = *begin_list;
	t_list	*prev = NULL;

	while (current) //Loop until the end of the list is reached
	{
		if (cmp(current->data, data_ref) == 0) //Check if the current node's data is equal to data_ref
		{
			if (prev == NULL) //If equal, and the current node is the head node
				*begin_list = current->next; //Update the current pointer to point to the next node before removal
			else //If equal, but the current node is not the head node
				prev->next = current->next; //Update the previous node's next element to skip the current node
			free(current); //After the node removal (via skipping), de-allocate the memory of the removed node
			current = prev; //Reset `current` to point to the previous node to recheck the current position in the updated list
		}
		prev = current; //`prev` now points to the node that current is currently pointing to. This keeps track of the previous node in the linked list before any removal happens
		current = current->next; //In the next iteration of the loop, current will move to the next node
	}
}

#include <stdio.h>
#include <string.h>

int		main(void)
{
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->data = "apple";
	node2->data = "orange";
	node3->data = "banana";

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	t_list *current = node1;

	printf("Original list:\n");
	while (current)
	{
		printf("%s -> ", (char *)current->data);
		current = current->next;
	}
	printf("NULL\n");
	char *data_ref = "orange";
	ft_list_remove_if(&node1, data_ref, &strcmp);
	printf("List after removal of \"%s\":\n", data_ref);
	current = node1;
	while (current)
	{
		printf("%s -> ", (char *)current->data);
		current = current->next;
	}
	printf("NULL\n");
	return (0);
}