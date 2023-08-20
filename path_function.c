#include "shell.h"
/**
 * *find_command_path - the function gets the full path of a command.
 * @command: character command to find.
 * Return: full path of the command.
 * Else: NULL - if the command was not found.
 */
char *find_command_path(char *command)
{
	char *pth = NULL, *pth_cp = NULL, *pth_tok = NULL;
	char *file_pth = NULL, *new_command = NULL;
	int cmd_len, dir_len;
	struct stat buffer;

	pth = _getenv("PATH");
	if (pth)
	{
		pth_cp = _strdup(pth);
		cmd_len = _strlen(command);
		pth_tok = _strtok(pth_cp, ":");

		while (pth_tok)
		{
			dir_len = _strlen(pth_tok);
			file_pth = malloc(cmd_len + dir_len + 3);

			_strcpy(file_pth, pth_tok);
			_strcat(file_pth, "/");
			_strcat(file_pth, command);
			file_pth[cmd_len + dir_len + 1] = '\0';

			if (stat(file_pth, &buffer) == 0)
			{
				new_command = file_pth;
				break;
			}
			else
			{
				free(file_pth);
				pth_tok = _strtok(NULL, ":");
			}
		}
		free(pth_cp);
		if (stat(command, &buffer) == 0)
		{
			new_command = command;
		}
	}
	return (new_command);
}
