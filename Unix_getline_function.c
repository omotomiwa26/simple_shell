#include "shell.h"
/**
 * get_line - Function reads an entire line from stream
 * 
 * Return: total bytes of line read from CLI input
 **/

char *get_line() 
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_pos = 0;
	static size_t buffer_size = 0;

	/*Initialize a dynamic buffer to store the line*/
	char* line = NULL;
	/*size_t line_size = 0;*/
	size_t line_length = 0;

	while (1) 
	{
		/*If buffer is empty, read more data from input source*/
		if (buffer_pos >= buffer_size) 
		{
			buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buffer_pos = 0;

			if (buffer_size <= 0) 
			{
				break;
			}
		}
		/*Search for newline character in buffer*/
		while (buffer_pos < buffer_size)
		{
			char current_char = buffer[buffer_pos++];
			if (current_char == '\n') 
			{
				/*Allocate memory for line and copy characters*/
				line = realloc(line, line_length + 1);
				line[line_length] = '\0';
				return (line);
			}
			else
			{
				/*Append character to line*/
				line = realloc(line, line_length + 1);
				line[line_length++] = current_char;
			}
		}
	}
	/*Clean up and return NULL if no more lines*/
	free(line);
	return (NULL);
}
