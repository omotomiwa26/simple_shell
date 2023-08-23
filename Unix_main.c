#include "shell.h"

/**
 * main - program executes the Unix shell command line.
 * @argc: integer of argument count.
 * @argv: array pointer to strings of C.L arguments.
 * Return: 0.
 */

int main(int argc, char *argv[])
{
	char *unix_input;/***input_arg;*/
	ssize_t file_check;
	int /*exe_env,*/ exe_stat = 0;

	(void)argc;
	/*(void)argv;*/

	while (1)
	{
		unix_input = NULL, file_check = 0;
		unix_input = shell_prompt(&file_check);
		argv = command_tokens(unix_input, argv, file_check);
		if (argv[0] == NULL)
		{
			free(unix_input);
			free(argv);
			continue;
		}
		if (_strncmp(argv[0], "exit", 4) == 0)
		{
			free(unix_input);
			exit_prompt(argv, exe_stat);
			free_array_vectors(argv);
			continue;
		}
		exe_stat = exec_command(argv);
		if (exe_stat == 1)
		{
			display_error_message(argv, "File not found");
		}
		if (execute_env(argv) != 0)
		{
			free(unix_input);
		free_array_vectors(argv);
		}
	}
	return (0);
}
