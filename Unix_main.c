#include "shell.h"

/**
 * main - program executes the Unix shell command line.
 * @argc: integer of argument count.
 * @argv: array pointer to strings of C.L arguments.
 * Return: 0.
 */

int main(int argc, char *argv[])
{
	char *unix_input;
	ssize_t file_check;
	int exe_stat = 0;

	(void)argc;

	while (1)
	{
		unix_input = NULL, file_check = 0;
		unix_input = shell_prompt(&file_check);
		argv = command_tokens(unix_input, file_check);

		if (argv[0] == NULL)
		{
			continue;
		}
		/*if (_strcmp(argv[0], "exit") == 0)
		  {
		  free(unix_input);
		  free_array_vectors(argv);
		  exit_shell(argv, exe_stat);
		  free_array_vectors(argv);
		  break;
		  }*/
		/*if (execute_env(argv) != 0)
		{
			free(unix_input);
			free_array_vectors(argv);
			continue;
		}*/
		exe_stat = exec_command(argv);
		if (exe_stat == 1)
			display_error_message(argv, "File not found");
		/*free(unix_input);*/
		/*free_array_vectors(argv);*/
		if (execute_env(argv) != 0)
		  {
		  /*free_array_vectors(argv);*/
		  }
	}
	return (0);
}
