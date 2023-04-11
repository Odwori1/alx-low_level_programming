#include "main.h"
/**
* main - check the code
* @ac: arguments to the compiled file
* @av: arguments to the compiled file
* Return: Always 0.
*/
int main(int ac, char **av)
{
ssize_t t;

if (ac != 2)
{
dprintf(2, "Usage: %s filename\n", av[0]);
exit(1);
}
t = read_textfile(av[1], 114);
printf("\n(printed chars: %li)\n", t);
t = read_textfile(av[1], 1024);
printf("\n(printed chars: %li)\n", t);
return (0);
}
