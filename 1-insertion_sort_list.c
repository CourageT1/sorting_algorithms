#include "sort.h"

/**
 * swap_nodes - swap two nodes in a doubly linked list
 * @h: pointer to the head of the list
 * @n1: pointer to the first node to swap
 * @n2: second node to swap
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
 * insertion_sort_list - sorts doubly linked list of integers
 * @list: pointer to the head of a doubly-linked list of integers
 * Description: prints list after each swap
 */
void insertion_sort_list(listint_t **list)
{
listint_t *iter, *insert, *tmp;

if (!list || !(*list) || !(*list)->next)
	return;
for (iter = (*list)->next; iter != NULL; iter = tmp)
{
tmp = iter->next;
insert = iter->prev;
while (insert != NULL && iter->n < insert->n)
{
	swap_nodes(list, &insert, iter);
	print_list((const listint_t *)*list);
}
}
}

/**
 * create_node - creates a new node
 * Description:  creates a new node with the given integer value
 * and returns a pointer to it.
 * Return: new node
 */
listint_t *create_node()
{
listint_t *new_node = malloc(sizeof(listint_t));

if (new_node)
{
	new_node->prev = NULL;
	new_node->next = NULL;
}
return (new_node);
}

/**
 * add_node -  adds a new node to the end of the doubly linked list.
 * @list: list to add node
 * @new_node: new created node
 */
void add_node(listint_t **list, listint_t *new_node)
{
listint_t *temp = *list;

if (!(*list))
{
*list = new_node;
return;
}
while (temp->next)
temp = temp->next;

temp->next = new_node;
new_node->prev = temp;
}
