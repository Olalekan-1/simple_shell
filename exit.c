#include "main.h"
/**
 * __exit - function exit shell
 * @cmd: The command - exit
 * @status: exit status
 * @filename: filename..
 * Return: exit status
 */


int __exit(char **cmd, int status, char *filename)
{
	if (cmd[1] != NULL)
	{
		status = _atoi(cmd[1]);
		if (status != 0 || _strcmp(cmd[1], "0") == 0)
		{
			free_memory_pp(cmd);
			exit(status);
		}
		else
		{
			_putss(filename);
			_putss(": ");
			_putss(cmd[0]);
			_putss(": ");
			_putss("Illegal number: ");
			_putss(cmd[1]);
			_putchar('\n');
			return (1);
		}
	}
	exit(status);
	free_memory_pp(cmd);
	exit(status);
}

