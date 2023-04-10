#include "main.h"

/**
* read_textfile - reads a text file and prints it to the POSIX stdout
* @filename: name of the file to read
* @letters: number of letters to read and print
*
* Return: the number of letters read and printed, or 0 on failure
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t n_read, n_written, total = 0;
char *buf;

if (!filename)
return (0);

buf = malloc(sizeof(char) * (letters + 1));
if (!buf)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
{
free(buf);
return (0);
}

while ((n_read = read(fd, buf, letters)) > 0)
{
buf[n_read] = '\0';
n_written = write(STDOUT_FILENO, buf, n_read);
if (n_written == -1 || n_written != n_read)
{
free(buf);
close(fd);
return (0);
}
total += n_read;
}

free(buf);
close(fd);

if (n_read == -1)
return (0);

return (total);
}
