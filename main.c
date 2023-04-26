#include "main.h"


/**
 * main - main to print shell
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 for success
 */


int main(int argc __attribute__((unused)), char *argv[])
{
	int (*builtin)(char **, int, char *);
	char **line;
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t bytes_read;
	int status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		bytes_read = getline(&lineptr, &n, stdin);
		if (bytes_read == -1)
		{
			_putchar(10);
			break;
		}
		if (*lineptr == '\n' || *lineptr == '\0')
			continue;
		line = parser(lineptr);
		if (!line || !line[0])
		{
			free(line);
			continue;
		}
		builtin = check_builtins(line);
		if (builtin)
		{
			status = builtin(line, status, argv[0]);
			free_memory_pp(line);
			continue;
		}
		else
			status = execmd(line);
		free_memory_pp(line);
	}
	if (lineptr != NULL)
		free(lineptr);
	return (0);
}

