#include "shell.h"

char *_getline()
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_length;
	static size_t position;

	char *line = NULL;
	size_t line_length = 0;
	size_t newline_index = 0;
	size_t chunk_length, i;

	while (1)
	{
		if (position >= buffer_length)
		{
			buffer_length = read(0, buffer, BUFFER_SIZE);
			if (buffer_length == 0)
				break;
			if (buffer_length == (size_t)-1)
				return (NULL);
			position = 0;
		}

		newline_index = position;
		while (newline_index < buffer_length && buffer[newline_index] != '\n')
			newline_index++;
		chunk_length = newline_index - position;
		line = realloc(line, (line_length + chunk_length + 1) * sizeof(char));
		if (line == NULL)
			return (NULL);
		for (i = 0; i < chunk_length; i++)
			line[line_length + i] = buffer[position + i];
		line_length += chunk_length;
		position = newline_index + 1;
		if (newline_index < buffer_length && buffer[newline_index] == '\n')
		{
			line[line_length] = '\0';
			return (line);
		}
	}

	return (line);
}
