#include "shell.h"
/**
 * get_line - Function reads an entire line from stream
 * @lineptr: pointer to a pointer to a character
 * @n: pointer to value
 * @stream: pointer to FILE representing the stream to read from
 * Return: total bytes of line read from CLI input
 **/
size_t get_line(char **lineptr, size_t *n, FILE *stream)
{
int fd;
size_t bufsize, chars_read, tot_chars_read;
char *buffer, chars, *new_buffer;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	fd = fileno(stream);
	bufsize = *n;
	buffer = *lineptr;

	if (buffer == NULL)
	{
		bufsize = 128;
		buffer = (char *)malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			return (-1);
		}
	}
chars_read = 0, tot_chars_read = 0;
	while (read(fd, &chars, 1) == 1)
	{
		if (tot_chars_read >= bufsize - 1)
		{
			bufsize *= 2;
			new_buffer = (char *)realloc(buffer, bufsize * sizeof(char));
			if (new_buffer == NULL)
			{
				free(buffer);
				return (-1);
			}
			buffer = new_buffer;
		}
		buffer[tot_chars_read++] = chars;
		if (chars == '\n')
		{
			break;
		}
	}
	buffer[tot_chars_read] = '\0';
	*lineptr = buffer;
	*n = bufsize;
	if (tot_chars_read == 0 && chars_read == 0)
	{
		/*free(buffer);*/
		return (-1);
	}
	return (tot_chars_read);
}
