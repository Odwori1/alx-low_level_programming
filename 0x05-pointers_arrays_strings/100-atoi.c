#include "main.h"

/**
* _atoi - converts a string to an integer
* @s: pointer to a string
* Return: integer
*/
int _atoi(char *s)
{
	unsigned int i = 0, j = 0, k = 0, l = 0, m = 0;
	int num[10];

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			j++;
		}
		if (s[i] >= '0' && s[i] <= '9')
		{
			num[k] = s[i] - '0';
			k++;
		}
		if (k > 0 && (s[i] < '0' || s[i] > '9'))
		{
			break;
		}
		i++;
	}
	for (l = 0; l < k; l++)
	{
		m = m * 10 + num[l];
	}
	if (j % 2 != 0)
	{
		m = m * -1;
	}
	return (m);
}
