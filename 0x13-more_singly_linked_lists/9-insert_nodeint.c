#include "lists.h"
/**
* insert_nodeint_at_index - sets new node given position in linked list
* @head: pointer to the head of the linked list
* @idx: index where the new node should be inserted
* @n: value to be stored in the new node
*
* Return: pointer to the new node, or NULL if it fails
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current_node;
	unsigned int i;

	if (head == NULL)
	return (NULL);

	if (idx == 0)
	return (add_nodeint(head, n));

	current_node = *head;
	for (i = 0; i < idx - 1 && current_node != NULL; i++)
	current_node = current_node->next;

	if (current_node == NULL)
	return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	return (NULL);

	new_node->n = n;
	new_node->next = current_node->next;
	current_node->next = new_node;

return (new_node);
}
