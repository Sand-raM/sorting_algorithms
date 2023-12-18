#include "sort.h"


void move_left(listint_t *curr, listint_t *prev, listint_t **head);

/**
* cocktail_sort_list - coctail sort in doubly linked list
* @list: A Doubly linked list
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *cl;
	listint_t *max = NULL;
	listint_t *min = NULL;

	if (!list || !(*list) || (*list)->next == NULL)
		return;
	cl = *list;
	do {
		while (cl->next)
		{
			if (cl->n > cl->next->n)
				move_left(cl->next, cl, list);
			else
				cl = cl->next;
		}
		max = cl;
		while (cl->prev != min)
		{
			if (cl->n < cl->prev->n)
				move_left(cl, cl->prev, list);
			else
				cl = cl > prev;
		}
		min = cl;
	} while (min != max);
}

/**
* move_left - swaps two members of a list
*
* @cur: the current node
* @prev: the previous node
* @head:the  head of list
*/
void move_left(listint_t *cur, listint_t *prev, listint_t **head)
{
	listint_t *swap1 = cur->next;
	listint_t *swap2 = prev->prev;

	if (swap1 != NULL)
		swap1->prev = prev;
	if (swap2 != NULL)
		swap2->next = cur;
	cur->prev = swap2;
	prev->next = swap1;
	cur->next = prev;
	prev->prev = cur;
	if (*head == prev)
		*head = cur;
	print_list(*head);
}
