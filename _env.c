#include "main.h"

/**
 * _env - To print list of of enviroment variable
 * @cmd:...
 * @status:...
 * @filename:...
 * Return: 0 for sucess
 */

int _env(char **cmd, int status, char *filename)
{
	int i = 0;
	(void)cmd;
	(void)status;
	(void)filename;
	while (environ[i] != NULL)
	{
		_puts(environ[i]);
		i++;
	}
	/*free_memory_pp(environ);*/
	return (0);
}


