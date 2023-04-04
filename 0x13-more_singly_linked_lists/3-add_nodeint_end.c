#include "lists.h"
/**
* add_nodeint_end - adds a new node at the end of a listint_t list
* @head: pointer to a pointer to the head of the list
* @n: integer value to store in the new node
*
* Return: address of the new element, or NULL if it failed
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
	{
	listint_t *new_node, *current;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	return (NULL);

	/* Set the values of the new node */
	new_node->n = n;
	new_node->next = NULL;

	/* If the list is empty, set the head pointer to point to the new node */
	if (*head == NULL)
		{
		*head = new_node;
		return (new_node);
		}

	/* Traverse the list until the last node */
	current = *head;
	while (current->next != NULL)
	current = current->next;

	/* Set the next pointer of the last node to the new node */
	current->next = new_node;

	return (new_node);
	}
