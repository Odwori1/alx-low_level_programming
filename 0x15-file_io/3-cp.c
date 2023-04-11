#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
* main - Copies the content of a file to another file.
*
* @argc: The number of arguments passed to the program.
* @argv: An array of strings containing the arguments passed to the program.
*
* Return: 0 if success, otherwise an exit code.
*/
int main(int argc, char **argv)
{
int fd_from, fd_to, ret_read, ret_write;
char buf[1024];

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
exit(97);
}

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}

do {
ret_read = read(fd_from, buf, 1024);
if (ret_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
close(fd_from);
close(fd_to);
exit(98);
}

ret_write = write(fd_to, buf, ret_read);
if (ret_write == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(fd_from);
close(fd_to);
exit(99);
}
} while (ret_read > 0);

if (close(fd_from) == -1 || close(fd_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd\n");
exit(100);
}

return (0);
}
