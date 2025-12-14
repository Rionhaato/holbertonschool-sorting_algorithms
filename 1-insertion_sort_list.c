#include "sort.h"

/**
 * swap_nodes - swaps two adjacent nodes (left, right) in a doubly linked list
 * @list: pointer to head pointer of the list
 * @left: left node
 * @right: right node
 */
static void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	right->prev = left->prev;
	left->prev = right;
	left->next = right->next;
	right->next = left;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *                       in ascending order using insertion sort
 * @list: double pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *scan;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		scan = current;
		while (scan->prev && scan->prev->n > scan->n)
		{
			swap_nodes(list, scan->prev, scan);
			print_list(*list);
		}
		current = current->next;
	}
}
