#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *insert;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

for (current = (*list)->next; current != NULL; current = current->next)
{
insert = current->prev;

while (insert != NULL && insert->n > current->n)
{
if (insert->prev == NULL)
{
current->prev = NULL;
(*list)->prev = current;
(*list) = current;
}
else
{
current->prev = insert->prev;
insert->prev->next = current;
}

insert->next = current->next;

if (current->next != NULL)
current->next->prev = insert;

current->next = insert;
insert->prev = current;

insert = current->prev;
if (insert == NULL)
break;
print_list(*list);
}
}
}
