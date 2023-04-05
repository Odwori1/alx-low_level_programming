#include "lists.h"

/**
* print_listint_safe - Prints a listint_t linked list safely
* @head: Pointer to the head node
*
* Return: Number of nodes in the list
*/
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *node1, *node2;
	size_t count = 0;

	if (head == NULL)
	exit(98);

	node1 = head;
	node2 = head->next;

	while (node2 != NULL && node2 < node1)
	{
	printf("[%p] %d\n", (void *) node1, node1->n);
	count++;
	node1 = node1->next;
	node2 = node2->next;
	if (node2 != NULL && node2 < node1)
	node2 = node2->next;
	}

	printf("[%p] %d\n", (void *) node1, node1->n);
	count++;

	if (node2 != NULL)
	{
	printf("-> [%p] %d\n", (void *) node2, node2->n);
	count++;
	}

	return (count);
}
