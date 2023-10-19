#include "shell.h"

/**
 * _strncmp - function compares the first @num character
 * of @str1 and @str2
 * @str1: pointer to first string character
 * @str2: pointer to second string character
 * @num: number of bytes to compare
 * Return: 1 - if @str1 > @str2
 * Else: -1
 */

int _strncmp(const char *str1, const char *str2, size_t num)
{
	size_t i;

	for (i = 0; i < num; ++i)
	{
		if (str1[i] != str2[i])
		{
			return ((str1[i] < str2[i]) ? -1 : 1);
		}
		else if (str1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
/**
 * exit_prompt - function exits the command line prompt
 * @exit_command: command argument entered
 * @exit_status: integer coversion of message displayed on exit
 * Return: NULL
 * Else: Exit the shell prompt
 */
void exit_prompt(char **exit_command, int exit_status)
{
	if (exit_command[1])
	{
		exit_status = _atoi(exit_command[1]);
	}
	free_array_vectors(exit_command);
	exit(exit_status);
}
/**
 * create_env - creates an environment variable
 * @env_name: name of the variable
 * @env_value: value of the variable
 *
 * Return: the new variable
 */

char *create_env(char *env_name, char *env_value)
{
	char *var = NULL, *new_var = NULL;

	new_var = _strcat(env_name, "=");
	if (new_var == NULL)
		return (NULL);

	var = _strcat(new_var, env_value);
	if (var == NULL)
	{
		free(new_var);
		return (NULL);
	}
	free(new_var);
	return (var);
}

/**
 * _echo - Functions executes echo command
 * @args: Argument variable pointer
 * Return: 1 - if succesful
 * Else: -1
 **/

int _echo(char *args)
{
	char *value;

	value = _getenv(args);
	if (value)
	{
		write(1, value, _strlen(value));
	}
	return (1);
}
