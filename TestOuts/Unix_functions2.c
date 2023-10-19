#include "shell.h"

/**
 * _strcmp - function compares two strings.
 * @s1: string to be compared.
 * @s2: second string to be compared.
 *
 * Return: The integer difference of s1 and s2.
 */

int _strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/**
 * *_strtok - function tokenizes a string given a delimiter.
 * @str: pointer to the string to be tokenized
 * @delim: pointer to string containing the delimiter
 * Return: pointer to next token.
 * Else: NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *new_tok;
	char *tok;

	if (str != NULL)
	{
		new_tok = str;
	}
	if (new_tok == NULL)
	{
		return (NULL);
	}
	/*Find the start of the next token*/
	tok = new_tok;
	while (*tok != '\0' && _strchr(delim, *tok) != NULL)
	{
		tok++;
	}
	/*If we've reached the end of the string, there are no more tokens to return*/
	if (*tok == '\0')
	{
		new_tok = NULL;
		return (NULL);
	}
	/*Find the end of the current token*/
	new_tok = tok + 1;
	while (*new_tok != '\0' && _strchr(delim, *new_tok) == NULL)
	{
		new_tok++;
	}
	/*If we've reached the end of the string, new_token should be NULL*/
	if (*new_tok == '\0')
	{
		new_tok = NULL;
	}
	else
	{
		*new_tok = '\0';
		new_tok++;
	}
	return (tok);
}
