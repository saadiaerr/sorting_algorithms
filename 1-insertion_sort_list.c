#include "sort.h"

void swap(listint_t *a, listint_t *b);

/**
 * insertion_sort_list - insertion sort lst
 * @list: lst
 *
 * Return: prev
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ih, *jh;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}

	ih = (*list)->next;
	while (ih)
	{
		jh = ih;
		ih = ih->next;
		while (jh && jh->prev)
		{
			if (jh->prev->n > jh->n)
			{
				swap(jh->prev, jh);
				if (!jh->prev)
					*list = jh;
				print_list((const listint_t *)*list);
			}
			else
			{
				jh = jh->prev;
			}
		}
	}
}

/**
 * swap - swaps 2 nodes
 * @a: adrs of first node
 * @b: adrs of second node
 *
 * Return: void
 */
void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}
