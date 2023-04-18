#include "main.h"


/**
 * get_path - function to get the path of a command
 * @cmd: the command
 * Return: The path
 */

char *get_path(char *cmd)
{	char *path;
	char *path_cpy;
	char *token;
	int cmd_len, token_len;
	char *file_path;
	struct stat buffer;
	const char *delim = ":";

	path = _getenv("PATH");
	if (path)
	{
		path_cpy = _strdup(path);
		cmd_len = _strlen(cmd);
		token = _strtok(path, delim);
		while (token != NULL)
		{
			token_len = _strlen(token);
			file_path = malloc(token_len + cmd_len + 2);
			_strcpy(file_path, token);
			_strcat(file_path, "/");
			_strcat(file_path, cmd);
			_strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_cpy);
				return (file_path);
			}
			else
			{
				free(file_path);
				token = _strtok(NULL, delim);
			}
		}
	}
	free(path_cpy);
	if (stat(cmd, &buffer) == 0)
	{
		return (cmd);
	}
	return (NULL);
}

