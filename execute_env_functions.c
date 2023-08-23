#include "shell.h"
/**
 * execute_env - function executes found built-in function.
 * @args: pointer array of arguments.
 * Return: 0 - if success.
 */
int execute_env(char **args)
{
	if (_strncmp(args[0], "env", 3) == 0)
	{
		show_env();
	}	
	/*else if (_strncmp(args[0], "setenv", 6) == 0)
	{
		if (args[1] && args[2])
		{
			set_env(args[1], args[2]);
		}
		else
		{
			write(2, "Error: Setenv Failed\n", 22);
		}
	}
	else if (_strncmp(args[0], "unsetenv", 8) == 0)
	{
		if (args[1])
		{
			unset_env(args[1]);
		}
		else
		{
			write(2, "Error: Unsetenv Failed\n", 24);
		}
	}*/
	else if (_strncmp(args[0], "echo", 4) == 0)
	{
		if (args[1])
		{
			_echo(args[1]);
		}
		else
		{
			write(2, "Error: Enter string to echo\n", 29);
		}
	}
	return (1);
}
