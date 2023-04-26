#include "main.h"


/**
 * execmd - function to execute a comand
 * @argv: argument vector;
 * @filename: filename
 * Return: execution status
 */


int execmd(char **argv, char *filename)
{
	char *command = argv[0]; /**cmd = get_path(command);*/
	pid_t pid;
	int status;
	/*char *cmd = get_path(argv[0]);*/

	/*if (cmd == NULL)*/
	/*{*/
		/*perror(cmd);*/
		/*return (1);*/
	/*}*/

	pid = fork();
	if (pid < 0)
	{
		perror("Error");
		exit(1);
	}

	else if (pid == 0)
	{
		execve(command, argv, NULL);
		perror(filename);
		exit(1);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(1);
		}
	}
	return (0);
}


