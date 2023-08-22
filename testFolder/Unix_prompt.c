#include "shell.h"

/**
 * shell_prompt - function reads unix shell prompts and display inputs
 * @file_check: pointer to the getline input
 * Return: character to the prompt_input
 *
 */

char *shell_prompt(ssize_t *file_check)
{
	char *dis_prompt = "(?) ", *newline_pos;
	static char *prompt_input = NULL;
	static size_t buffer_size = 0;
	size_t chars_read;

	if (isatty(STDIN_FILENO))
	{
		write(1, dis_prompt, _strlen(dis_prompt));
	}
	chars_read = get_line(&prompt_input, &buffer_size, stdin);
	*file_check = chars_read;

	if (*file_check == -1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "Logging Out From simple shell (?) .....", 43);
		/*free(prompt_input);*/
		exit(EXIT_SUCCESS);
	}

	if (*file_check == 0 && isatty(STDIN_FILENO))
	{
		free(prompt_input);
		return (shell_prompt(file_check));
	}

	newline_pos = _strchr(prompt_input, '\n');

	if (newline_pos)
		newline_pos = '\0';
	return (prompt_input);
}
