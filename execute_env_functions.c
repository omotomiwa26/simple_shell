#include "shell.h"
/**
 * execute_env - function executes found built-in function.
 * @args: pointer array of arguments.
 * Return: 0 - if success.
 */
int execute_env(char **args)
{
	if (_strncmp(args[0], "env", _strlen(args[0])) == 0)
	{
		show_env();
	}
	else if (_strncmp(args[0], "echo", _strlen(args[0])) == 0)
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
