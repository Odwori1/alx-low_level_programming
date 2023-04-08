#include "main.h"
/**
* clear_bit - sets the value of a bit to 0 at a given index
* @n: a pointer to the number containing the bit
* @index: the index of the bit, starting from 0
*
* Return: 1 if the operation was successful, or -1 if an error occurred
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
if (index >= sizeof(unsigned long int) * 8)
return (-1); /*index out of range*/

*n &= ~(1ul << index);
return (1);
}
