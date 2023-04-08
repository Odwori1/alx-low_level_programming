#include "main.h"

/**
* flip_bits - returns the number of bits you would need to flip to get from one
*             number to another
* @n: the first number
* @m: the second number
*
* Return: the number of bits that need to be flipped
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int bits_to_flip = n ^ m;
unsigned int count = 0;

while (bits_to_flip > 0)
{
count += bits_to_flip & 1;
bits_to_flip >>= 1;
}

return (count);
}
