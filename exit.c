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
			/*free(cmd[1]);*/
			/*free(cmd);*/
			_exit(status);
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
			status = 1;
		}
	}
	else
	{
		status = 0;
		_exit(status);
	}
	free_memory_pp(cmd);
	_exit(status);
}
