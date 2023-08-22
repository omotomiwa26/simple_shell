#include "shell.h"
/**
 * command_tokens - Function splits user's command input into tokens
 * @cmd_input: pointer to inputted command
 * @file: size of file read
 * Return: array of pointer to strings
 */
char **command_tokens(char *cmd_input, char **cmd, ssize_t file)
{
	char *tok, *cmd_input_cpy;
	const char *delimiter = " \n";
	int tok_len, tok_cnt = 0, i = 0;

	cmd_input_cpy = malloc(sizeof(char) * (file + 2));
	if (cmd_input_cpy == NULL)
	{
		perror("Error: Memory Allocation Failed");
		free(cmd_input_cpy);
		return (NULL);
	}
	_strcpy(cmd_input_cpy, cmd_input);
	tok = _strtok(cmd_input, delimiter);

	while (tok)
	{
		tok_cnt++;
		/*free(tok);*/
		tok = _strtok(NULL, delimiter);
	}
	tok_cnt++;

	cmd = malloc(sizeof(char *) * tok_cnt);
	if (cmd == NULL)
	{
	perror("Error: Memory Allocation Failed");
	free(cmd);
	return (NULL);
	}
	tok = _strtok(cmd_input_cpy, delimiter);
	for (i = 0; tok != NULL; i++)
	{
		tok_len = _strlen(tok);
		cmd[i] = malloc(sizeof(char) * tok_len + 1);
		cmd[i][tok_len] = '\0';
		_strcpy(cmd[i], tok);
		/*free(tok);*/
		tok = _strtok(NULL, delimiter);
	}
	free(tok);
	cmd[i] = NULL;
	free(cmd_input_cpy);
	return (cmd);
}
