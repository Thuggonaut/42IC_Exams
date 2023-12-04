/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}
*/

#include <stddef.h>

typedef struct s_list t_list;

struct s_list
{
        int     data;
        t_list  *next;
};

t_list  *sort_list(t_list* lst, int (*cmp)(int, int))
{
        int     tmp; //To store tempory value while nodes are being swapped

        t_list  *head = lst; //To keep track of the top node

        while (lst->next) //Loop until the end of the list is reached 
        {
                if (((*cmp)(lst->data, lst->next->data)) == 0) //Apply the compare function to the first two nodes, `0` means false, not sorted
                {
                        tmp = lst->data; //Assign to `tmp` the data of top node so we can swap the first two nodes
                        lst->data = lst->next->data; //Assign to the top node, the data of the second node
                        lst->next->data = tmp; //Assign the second node, what was previously the top node's data, completing the swap
                        lst = head; //Update the top node's pointer, which will now be the previous second node
                }
                else
                        lst = lst->next; //If 1, meaning true, then skip to the next node for comparison
        }
        lst = head; //Ensure that the pointer points to the beginning of the sorted list when the function returns
        return (lst);
}

/*
#include <stdio.h>
#include <stdlib.h>

int ascending(int a, int b)
{
        return (a <= b);
}

int     main(void)
{
        t_list  *node1 = (t_list *)malloc(sizeof(t_list));
        t_list  *node2 = (t_list *)malloc(sizeof(t_list));
        t_list  *node3 = (t_list *)malloc(sizeof(t_list));

        node1->data = 5;
        node2->data = 42;
        node3->data = -10;

        node1->next = node2;
        node2->next = node3;
        node3->next = NULL;

        t_list  *sorted = sort_list(node1, ascending);

        while (sorted != NULL)
        {
                printf("%d ", sorted->data);
                sorted = sorted->next;
        }

        free(node1);
        free(node2);
        free(node3);

        return(0);
}*/