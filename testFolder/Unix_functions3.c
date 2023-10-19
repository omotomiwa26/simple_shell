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
 * exit_shell - function exits the command line prompt
 * @argv_cmd: command argument entered
 * @exit_status: integer coversion of message displayed on exit
 * Return: NULL
 * Else: Exit the shell
 */
/*void exit_shell(char *argv_cmd[], int exit_status)
{
	char temp_char, *error_message = "Exiting Shell Failed";
	char exit_message[20];
	int i, digit, length = 0;
	int temp = exit_status;

	if (temp == 0)
	{
		exit_message[length++] = '0';
	}
	else
	{
		while (temp)
		{
			digit = temp % 10;
			exit_message[length++] = '0' + digit;
			temp /= 10;
		}
	}
	for (i = 0; i < length / 2; i++)
	{
		temp_char = exit_message[i];
		exit_message[i] = exit_message[length - i - 1];
		exit_message[length - i - 1] = temp_char;
	}
	exit_message[length] = '\0';
	if (argv_cmd[1])
	{
		exit_status = _atoi(argv_cmd[1]);
		if (exit_status >= 0)
		{
			write(1, exit_message, length);
			exit(exit_status);
		}
		else
		{
			write(1, error_message, _strlen(error_message));
			write(1, "\n", 1);
		}
	}
	exit(0);
}*/
 void exit_shell(char **exit_command, int exit_status)
{
exit_status = EXIT_SUCCESS;

if (exit_command[1])
exit_status = _atoi(exit_command[1]);

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

	if (args == NULL)
	{
		write(2, "Error: Enter string to echo", 30);
		return (-1);
	}

	value = _getenv(args);
	if (value)
	{
		write(1, value, _strlen(value));
	}
	return (1);
}
