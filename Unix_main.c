#include "shell.h"

/**
 * main - program executes the Unix shell command line.
 * @argc: integer of argument count.
 * @argv: array pointer to strings of C.L arguments.
 * Return: 0.
 */

int main(int argc, char *argv[])
{
	char *unix_input,**input_arg;
	ssize_t file_check;
	int exe_env, exe_stat = 0;

	(void)argc;
	(void)argv;

	while (1)
	{
		unix_input = NULL, file_check = 0;
		unix_input = shell_prompt(&file_check);
		input_arg = command_tokens(unix_input, input_arg, file_check);
		if (input_arg[0] == NULL)
		{
			free(unix_input);
			continue;
		}
		if (_strcmp(input_arg[0], "env") == 0)
		{
			free(unix_input);
			show_env();
			free_array_vectors(input_arg);
			continue;
		}
		if (_strcmp(input_arg[0], "exit") == 0)
		{
			free(unix_input);
			exit_shell(input_arg, exe_stat);
			free_array_vectors(input_arg);
			continue;
		}
		exe_stat = exec_command(input_arg);
		if (exe_stat == 1)
		{
			display_error_message(input_arg, "File not found");
		}
		exe_env = execute_env(input_arg);
		if (exe_env != 0)
			free(unix_input);
		free_array_vectors(input_arg);
		/*exe_stat = exec_command(input_arg);
		  if (exe_stat == 1)
		  display_error_message(input_arg, "File not found");
		  free(unix_input);
		  free_array_vectors(input_arg);*/
	}
	return (0);
}
