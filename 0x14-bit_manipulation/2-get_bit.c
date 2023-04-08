#include "main.h"
/**
* get_bit - returns the value of a bit at a given index
* @n: the number containing the bit
* @index: the index of the bit, starting from 0
*
* Return: the value of the bit at index index, or -1 if an error occurred
*/
int get_bit(unsigned long int n, unsigned int index)
{
if (index >= sizeof(unsigned long int) * 8)
return (-1); /*index out of range*/

return ((n >> index) & 1);
}
