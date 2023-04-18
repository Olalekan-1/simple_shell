#include "main.h"


/**
 * execmd - function to execute a comand
 * @argv: argument vector;
 * Return: execution status
 */

int execmd(char **argv)
{
	char *command = NULL, *cmd = NULL;
	pid_t pid;
	int status;

	if (!*argv)
	{
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (pid == 0)
	{
		if (argv)
		{
			command = argv[0];
			cmd = get_path(command);
			if (cmd != NULL)
			{
				if (execve(cmd, argv, environ) == -1)
				{
					perror("Error");
				}
			}
			else
			{
				perror(command);
				exit(1);
			}
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}

