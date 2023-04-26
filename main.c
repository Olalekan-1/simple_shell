#include "main.h"


/**
 * main - main to print shell
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 for success
 */


int main(int argc __attribute__((unused)), char *argv[])
{
	/*int (*builtin)(char **, int, char *);*/
	char **line = argv;
	char *lineptr = NULL;
	size_t n = 0;
	/*ssize_t bytes_read;*/
	/*int status = 0;*/

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		if (getline(&lineptr, &n, stdin) == -1)
		{
			free(lineptr);
			_putchar(10);
			exit(0);
		}
		if (lineptr == NULL)
			continue;
		lineptr[_strcspn(lineptr, "\n")] = '\0';

		line = parser(lineptr);
		/*builtin = check_builtins(line);*/
		/*if (builtin)*/
		/*{*/
			/*status = builtin(line, status, argv[0]);*/
			/*free_memory_pp(line);*/
		/*}*/
		execmd(line, argv[0]);
		free_memory_pp(line);
	}
	if (lineptr != NULL)
		free(lineptr);
	return (0);
}

