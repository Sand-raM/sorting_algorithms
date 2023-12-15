#include "sort.h"

/**
 * swap_nodes - swap two nodes in the listint_t lists.
 * @n1: pointer to the first node to be swaped
 * @n2: second node to swaped
 * @h: pointer to the head of the listint_t list.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of a doubly-linked list of intergers
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *itr, *del, *ptr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (itr = (*list)->next; itr != NULL, itr = ptr)
	{
		ptr = itr->next;
		del = itr->prev;
		while (del != NULL && itr->n < del->n)
		{
			swap_nodes(list, &del, itr);
			print_list((const listint_t *)*list);
		}
	}
}
