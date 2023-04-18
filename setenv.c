#include "main.h"


/*int _putenv(char *string)
{
	int res;
	char **env = environ;
	char *name, value;

	if (string == NULL)
	{
		return (-1);
	}

	name = _strtok(string, "=");
	value = _strtok(NULL, "");

	if (name == NULL || value == NULL)
	{
		return (-1);
	}

	while (*env != NULL)*/
