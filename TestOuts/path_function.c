#include "shell.h"
/**
 * *find_command_path - the function gets the full path of a command.
 * @command: character command to find.i
 * Return: full path of the command.
 * Else: NULL - if the command was not found.
 */
char *find_command_path(char *command)
{
	int dir_len, cmd_len, file_pth_len, i;
	char *file_pth, *pth_tok;
	char *pth, *pth_cp = NULL;
	struct stat buffer;

	pth = _getenv("PATH");
	if (pth == NULL || command == NULL)
	{
		return (NULL);
	}
	if (stat(command, &buffer) == 0)
		return (command);
	if (pth)
	{
		pth_cp = _strdup(pth);
		cmd_len = _strlen(command);
		pth_tok = _strtok(pth_cp, ":");
		while (pth_tok)
		{
			dir_len = _strlen(pth_tok);
			file_pth_len = cmd_len + dir_len + 2;
			file_pth = malloc(file_pth_len);
			file_pth[0] = '\0';
			for (i = 0; i < file_pth_len; i++)
				file_pth[i] = '\0';
			_strcpy(file_pth, pth_tok);
			_strcat(file_pth, "/");
			_strcat(file_pth, command);
			_strcat(file_pth, "\0");
			if (stat(file_pth, &buffer) == 0)
			{
				free(pth_cp);
				return (file_pth);
			}
			free(file_pth);
			pth_tok = _strtok(NULL, ":");
		}
	}
	free(pth_cp);
	return (NULL);
}
