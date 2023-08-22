#include "shell.h"

/**
 * _puterr - function writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 */

int _puterr(char c)
{
	return (write(2, &c, 1));
}

/**
 * free_array_vectors - Function frees all dynamically allocated memory
 * argument vectors.
 * @argv: argument vector memory to be freed.
 */
void free_array_vectors(char *argv[])
{
char **temp_argv = argv;

    do {
        free(*temp_argv);
        *temp_argv = NULL;
        temp_argv++;
    } while (*temp_argv != NULL);

    free(argv);
}
/**
 * display_error_message - Function prints an error message
 * to the standard error file
 * @argv: pointer array of program argument
 * @message: error message displayed
 */

void display_error_message(char **argv, char *message)
{
	int i;
	char *program_name = _getenv("_");

	if (program_name != NULL)
	{
		for (i = 0; program_name[i] != '\0'; i++)
		{
			_puterr(program_name[i]);
		}
		_puterr(':');
		_puterr(' ');
		_puterr('1');
		_puterr(':');
		_puterr(' ');
		for (i = 0; argv[0][i] != '\0'; i++)
		{
			_puterr(argv[0][i]);
		}
		_puterr(':');
		_puterr(' ');
		for (i = 0; message[i] != '\0'; i++)
		{
			_puterr(message[i]);
		}
		_puterr('\n');
	}
}

/**
 * _atoi - function converts a string to an integer.
 * @s: string to be converted.
 *
 *Return: integer value of converted string.
 */

int _atoi(char *s)
{
	int sig = 1;
	unsigned int number = 0;

	do {

		if (*s == '-')
			sig *= -1;

		else if (*s >= '0' && *s <= '9')
			number = (number * 10) + (*s - '0');

		else if (number > 0)
			break;
	}	while (*s++);

	return (number * sig);
}
