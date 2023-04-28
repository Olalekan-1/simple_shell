#include "main.h"


/**
 * execmd - function to execute a comand
 * @argv: argument vector;
 * @filename: filename
 * Return: execution status
 */


int execmd(char **argv, char *filename)
{
	char *command = NULL, *cmd = NULL;
	pid_t pid;
	int status;

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
				perror(filename);
				exit(1);
			}
		}
	}
	else
	{
		/*wait(&status);*/
		waitpid(pid, &status, 0);
		/*WEXITSTATUS(status);*/
	}
	return (WEXITSTATUS(status));
}

