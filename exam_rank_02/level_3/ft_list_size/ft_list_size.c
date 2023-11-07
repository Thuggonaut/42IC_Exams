/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/

int	ft_list_size(t_list *begin_list)
{
	int	len = 0;

	while (begin_list) //Check if the current node is not NULL by iterating through the list until the end is reached
	{
		begin_list = begin_list->next; //Move to the next element
		len++;
	}
	return (len);
}

/*
#include <stdlib.h>
#include <stdio.h>

int     main(void)
{
    t_list *node1 = (t_list *)malloc(sizeof(t_list));
    t_list *node2 = (t_list *)malloc(sizeof(t_list));
    t_list *node3 = (t_list *)malloc(sizeof(t_list));

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    printf("Size of the list is: %d\n", ft_lst_size(node1));

    free(node1);
    free(node2);
    free(node3);

    return 0;
}
*/