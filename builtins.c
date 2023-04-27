#include "main.h"

/**
 * check_builtins - function to check builtins
 * and point to the neccesary function
 * @name: builtin name (command)
 * Return: pointer to function
 */

int (*check_builtins(char **name))(char **, int, char *)
{	int i;
	/*int len;*/
	builtins builtin[] = {
		{"env", _env},
		{"cd", _cd},
		{"exit", __exit},
		{NULL, NULL}
		};
	i = 0;
	/*len = strlen(*name);*/
	while (builtin[i].name != NULL)
	{
		if (_strcmp(builtin[i].name, name[0]) == 0)

		{
			return (builtin[i].func);
		}
		i++;
	}
	return (NULL);
}

