#include "main.h"

/**
 * parser- function that parse and made token from str
 * @line: The string to parse
 * Return: The tokens
 */
char **parser(char *line)
{
	char **tok;
	int j = 0, token_num = 0;
	char *token;
	char *line_cpy;
	const char *delim = " \n";

	line_cpy = malloc(sizeof(char *) * _strlen(line) + 1);
	if (line_cpy == NULL)
		return (NULL);
	_strcpy(line_cpy, line);

	token = _strtok(line_cpy, delim);

	while (token != NULL)
	{
		token_num++;
		token = _strtok(NULL, delim);
	}
	token_num++;

	tok = malloc(sizeof(char *) * token_num);

	token = _strtok(line, delim);

	for (j = 0; token != NULL; j++)
	{
		tok[j] = malloc(sizeof(char *) *  _strlen(token) + 1);
		_strcpy(tok[j], token);
		token = _strtok(NULL, delim);
	}

	tok[j] = NULL;
	free_memory_p(line_cpy);
	return (tok);

}
