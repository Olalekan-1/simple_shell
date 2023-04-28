#include "main.h"
/**
 * __exit - function exit shell
 * @cmd: The command - exit
 * @status: exit status
 * @filename: filename..
 * Return: exit status
 */


int __exit(char **cmd, int status, char *filename)
{	int exit_status;

	if (!cmd || !cmd[0])
	{
		exit(status);
	}
	if (cmd[1] == NULL)
	{
		if (!isatty(STDIN_FILENO))
		{
			exit(status);
		}
		_putss(filename);
		_putss(": ");
		_putss(cmd[0]);
		_putss(": ");
		_putss("requires an argument\n");
		return (1);
	}

	exit_status = _atoi(cmd[1]);
	if ((!is_numeric(cmd[1])) || exit_status < 0)
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
	/*status = atoi(cmd[1]);*/
	free_memory_pp(cmd);
	exit(exit_status);
}

