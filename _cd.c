#include "main.h"

/**
 * _cd - To change the current working directory
 * @argv: argumenent vector
 * @argc: argument count
 * @filename: file name
 * Return: 0 for success
 */


int _cd(char **argv, int argc, char *filename)
{	char cwd[1024];
	char *home = _getenv("HOME"), *oldpwd = _getenv("OLDPWD"), *dir = NULL;
	(void)filename;
	(void) argc;
		if (dir == NULL)
		dir = home;
		if (argv[1] != NULL && _strcmp(argv[1], "-") == 0)
		{
			dir = oldpwd;
			if (dir == NULL)
			{
				perror("cd");
				return (1);
			}
		}
		else if (argv[1] != NULL)
		{
			dir = argv[1];
		}
		else
		{
			perror("cd");
			return (1);
		}
		if (chdir(dir) != 0)
		{
			perror("cd");
			return (1);
		}
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("getcwd");
			return (1);
		}
	setenv("OLDPWD", _getenv("PWD"), 1);
	setenv("PWD", cwd, 1);
	return (0);
}
