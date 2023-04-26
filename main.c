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

	while (1)
	{
		if (isatty(STDIN_FILENO))
		prompt();
		if (getline(&lineptr, &n, stdin) == -1)
		{
			/*_putchar(10);*/
			break;
		}
		if ((*lineptr == '\n') || (*lineptr == '\0'))
			continue;
		lineptr[strcspn(lineptr, "\n")] = '\0';
		line = parser(lineptr);
		if (!line || !line[0])
			continue;
		builtin = check_builtins(line);
		if (builtin)
		{
			status = builtin(line, status, argv[0]);
			free_memory_pp(line);
			continue;
		}
		execmd(line, argv[0]);
		free_memory_pp(line);
	}
	if (lineptr != NULL)
	{
		free(lineptr);
	}
	return (0);
}

