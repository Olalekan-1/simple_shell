#include "main.h"

/**
 * _getenv - To get an envirommental variable
 * @name: Name of variable
 * Return: pointer to value of variable
 */


char *_getenv(const char *name)
{
	int i;
	char **env = environ;

	while (*env != NULL)
	{
		for (i = 0; (*env)[i] != '=' && (*env)[i] == name[i]; ++i)
		{
		}
		if ((*env)[i] == '=' && name[i] == '\0')
		{
			return (&((*env)[i + 1]));
		}
		++env;
	}
	return (NULL);
}


