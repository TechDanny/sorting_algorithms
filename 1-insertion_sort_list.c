#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order
 * @list:list of integers
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node1, *node2;

	if (list == NULL || *list == NULL)
	{
		return;
	}
	node1 = (*list)->next;
	while (node1 != NULL)
	{
		node2 = node1->next;
		while (node1->prev != NULL && node1->prev->n > node1->n)
		{
			node1->prev->next = node1->next;
			if (node1->next != NULL)
			{
				node1->next->prev = node1->prev;
			}
			node1->next = node1->prev;
			node1->prev = node1->next->prev;
			node1->next->prev = node1;
			if (node1->prev == NULL)
			{
				*list = node1;
			}
			else
			{
				node1->prev->next = node1;
			}
			print_list(*list);
		}
		node1 = node2;
	}
}
