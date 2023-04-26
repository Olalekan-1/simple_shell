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
		return;
	}

	prompt_len = strlen(user) + strlen(host) + 6;
	prompt = malloc(prompt_len);
	if (!prompt)
	{
		_putss(prompt_str);
		return;
	}
	_strcpy(prompt, user);
	_strcat(prompt, "@");
	_strcat(prompt, host);
	_strcat(prompt, " ");
	_strcat(prompt, prompt_str);
	_putss(prompt);

	free(prompt);
}

