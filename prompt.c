#include "main.h"


/**
 * prompt - To print prompt to the screen
 * @void: void
 * Return: void
 */



void prompt(void)
{
	char *user = _getenv("LOGNAME");
	char *host = _getenv("HOSTNAME");
	char *prompt_str = "#cisfun$ ";
	char *prompt = NULL;
	size_t prompt_len;

	if (!user || !host)
	{
		_putss(prompt_str);
		fflush(stdout);
		return;
	}

	prompt_len = _strlen(user) + _strlen(host) + _strlen(prompt_str) + 6;
	prompt = malloc(prompt_len + 1);

	if (!prompt)
	{
		_putss("Error: failed to allocate memory\n");
		exit(1);
	}
	_strcpy(prompt, user);
	_strcat(prompt, "@");
	_strcat(prompt, host);
	_strcat(prompt, " ");
	_strcat(prompt, prompt_str);
	_putss(prompt);
	fflush(stdout);

	free(prompt);
}

