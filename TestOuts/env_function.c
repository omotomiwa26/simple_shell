#include "shell.h"
/**
 * _getenv - function returns an environment variable
 * @name: pointer to character variable
 * Return: path of environment variable
 * Else: NULL if variable does not exist
 */

char *_getenv(char *name)
{

	int name_len = _strlen(name);
	int a = 0;

	while (environ[a])
	{
		if (_strncmp(name, environ[a], name_len) == 0 && environ[a][name_len] == '=')
		{
			return (&environ[a][name_len + 1]);
		}
		a++;
	}

	return (NULL);
}

/**
 * show_env - function shows all environment variables
 * Return: Null
 */

void show_env(void)
{
	char *var;
	size_t len;
	int x = 0;

	while (environ[x] != NULL)
	{
		var = environ[x];
		len = _strlen(var);
		write(STDOUT_FILENO, var, len);
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}

/**
 * set_env - function sets or overwrites environment variable
 * @name: Array pointer name of variable
 * @value: Array pointer value of vaiable
 * Return: 0 - if variable is set
 * Else: -1
 */

int set_env(char *name, char *value)
{
	if (name && value)
	{
		create_env(name, value);
		return (0);
	}

	perror("Error: Set Environment Variables");
	return (-1);
}

/**
 * unset_env - function removes set environment variable.
 * @var_name: pointer to the variable to remove.
 * Return: 0 - if successful
 * Else: -1
 */

int unset_env(char *var_name)
{
	int x;
	size_t var_len;
	char **env_tem;

	var_len = _strlen(var_name);

	for (x = 0; environ[x]; x++)
	{
		if (_strncmp(environ[x], var_name, var_len) == 0)
		{
			env_tem = environ + x;

			free(env_tem[0]);
			while (env_tem[0])
			{
				env_tem[0] = env_tem[1];
				env_tem++;
			}
		}
	}

	return (0);
}
