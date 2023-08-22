#include "shell.h"
/**
 * exec_command - Function executes a command on CLI
 * with the given arguments.
 * @argv:  Array of strings for the command and its arguments.
 * Return: Executable file if found
 * Else: Error
 */
int exec_command(char *argv[])
{
	char *command = NULL, *new_command = NULL;
	pid_t child_pid = -1;
	int status = 0;

	if (argv == NULL || argv[0] == NULL)
	{
		return (1);
	}
	command = argv[0];
	new_command = find_command_path(command);
	
	if (new_command == NULL)
		return (1);
	if (argv && access(new_command, X_OK) != -1)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			display_error_message(argv, "Fork Error:");
		}
		else if (child_pid == 0)
		{
			if (execve(new_command, argv, NULL) == -1)
			{
			display_error_message(argv, "Execve Error:");
			}
			exit(0);
		}
		else
		{
			if (waitpid(child_pid, &status, 0) == -1)
			{
			display_error_message(argv, "Waitpid Error:");
			}
		}
		if (_strcmp(new_command, command) != 0)
		{
			free(new_command);
		}
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
		}
		return (status);
	}
	free(new_command);
	return (1);
}
