#include <stddef.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
listint_t *tmp;
if (a->prev != NULL)
a->prev->next = b;
if (b->next != NULL)
b->next->prev = a;

if (a->next == b)
{
a->next = b->next;
b->prev = a->prev;
a->prev = b;
b->next = a;
}
else
{
a->next->prev = b;
b->prev->next = a;
tmp = b->prev;
b->prev = a->prev;
a->prev = tmp;
tmp = a->next;
a->next = b->next;
b->next = tmp;
}

if (*list == a)
*list = b;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
int swapped = 1;
listint_t *start = *list;
listint_t *end = NULL;

if (list == NULL || *list == NULL)
return;

while (swapped)
{
swapped = 0;
while (start->next != end)
{
if (start->n > start->next->n)
{
swap_nodes(list, start, start->next);
swapped = 1;
print_list(*list);
}
else
start = start->next;
}
if (!swapped)
break;
swapped = 0;
end = start;
while (start->prev != NULL)
{
if (start->n < start->prev->n)
{
swap_nodes(list, start->prev, start);
swapped = 1;
print_list(*list);
}
else
start = start->prev;
}
start = (*list);
}
}
