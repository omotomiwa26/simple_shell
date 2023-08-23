#include "shell.h"
/**
 * get_line - Function reads an entire line from stream
 *
 * Return: total bytes of line read from CLI input
 **/

char *get_line()
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_pos;
	static size_t buffer_size;

	char *line = NULL;
	size_t line_length = 0;

	while (1)
	{
		if (buffer_pos >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buffer_pos = 0;

			if (buffer_size <= 0)
			{
				break;
			}
		}
		while (buffer_pos < buffer_size)
		{
			char current_char = buffer[buffer_pos++];

			if (current_char == '\n')
			{
				line = realloc(line, line_length + 1);
				line[line_length] = '\0';
				return (line);
			}
			else
			{

				line = realloc(line, line_length + 1);
				line[line_length++] = current_char;
			}
		}
	}
	free(line);
	return (NULL);
}
