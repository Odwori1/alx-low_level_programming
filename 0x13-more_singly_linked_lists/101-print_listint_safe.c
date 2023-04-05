#include "lists.h"

/**
* print_listint_safe - Prints a listint_t linked list.
* @head: Pointer to the beginning of the linked list.
*
* Return: The number of nodes in the linked list.
*/
size_t print_listint_safe(const listint_t *head)
{
const listint_t *nod1, *nod2;
size_t count = 0;

if (head == NULL)
exit(98);

nod1 = head;
nod2 = head->next;

while (nod2 != NULL && nod2 < nod1)
{
printf("[%p] %d\n", (void *)nod1, nod1->n);
count++;
nod1 = nod1->next;
nod2 = nod2->next;

if (nod2 != NULL && nod2 < nod1)
{
printf("[%p] %d\n", (void *)nod1, nod1->n);
count++;
nod1 = nod1->next;
nod2 = nod2->next;
}
}

if (nod2 != NULL)
{
printf("[%p] %d\n", (void *)nod1, nod1->n);
count++;
nod1 = nod1->next;
}

printf("-> [%p] %d\n", (void *)nod1, nod1->n);
count++;

return (count);
}
