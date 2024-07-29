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

typedef struct	  s_list
{
	struct s_list   *next;
	void			*data;
}				   t_list;

#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)()) {
	t_list *current = *begin_list;
	t_list *prev = NULL;

	while (current) {
		if (cmp(current->data, data_ref) == 0) {
			if (prev == NULL)
				current->data = current->next;
			else
				prev->next = current->next;
			free(current);
			current = prev;
		}
		prev = current;
		current = current->next;
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