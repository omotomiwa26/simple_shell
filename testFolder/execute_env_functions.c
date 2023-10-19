#include "shell.h"
/**
 * execute_env - function executes found built-in function.
 * @args: pointer array of arguments.
 * Return: 0 - if success.
 */
int execute_env(char **args)
{
	int exe_stat = 0;

	if (_strcmp(args[0], "exit") == 0)
	{
		exit_shell(args, exe_stat);
		free_array_vectors(args);
		free(args);
		/*break;*/
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		show_env();
	}	
	else if (_strcmp(args[0], "setenv") == 0)
	{
		if (args[1] && args[2])
		{
			return (set_env(args[1], args[2]));
		}
		else
		{
			write(2, "Error: Setenv Failed\n", 22);
		}
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (args[1])
		{
			return (unset_env(args[1]));
		}
		else
		{
			write(2, "Error: Unsetenv Failed\n", 24);
		}
	}
	else if (_strcmp(args[0], "echo") == 0)
	{
		if (args[1])
		{
			return (_echo(args[1]));

		}
		else
		{
			write(2, "Error: Enter string to echo\n", 29);
		}
	}
	return (1);
}
