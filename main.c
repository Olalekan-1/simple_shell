#include "main.h"


/**
 * main - main to print shell
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 for success
 */


int main(int argc __attribute__((unused)), char **argv)
{	int (*builtin)(char **, int, char *);
	size_t n = 0;
	char *lineptr = NULL;
	char **line = argv;
	int status = 0;
	int bytes_read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		bytes_read = getline(&lineptr, &n, stdin);
		if (bytes_read == -1 || bytes_read == EOF)
			break;
		if (lineptr[bytes_read - 1] == '\n')
			lineptr[bytes_read - 1] = '\0';
		line = parser(lineptr);
		if (line == NULL)
			continue;
		builtin = check_builtins(line);
		if (builtin)
		{
			status = builtin(line, status, argv[0]);
			free_memory_pp(line);
			continue;
		}
		execmd(line);
		free_memory_pp(line);
	}
	if (lineptr != NULL)
		free(lineptr);
	_putchar(10);
	return (0);
}
