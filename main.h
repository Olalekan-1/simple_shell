#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>


#define PROMPT "$ "


extern char **environ;

int (*check_builtins(char **cmd))(char **, int, char *);


void prompt(void);


/* strings manipulation*/
int _strlen(char *s);
void _puts(char *str);
int _putchar(char c);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *s);
char *_strtok(char *str, const char *del);
unsigned int _strspn(char *s, const char *accept);
size_t _strcspn(char *s, const char *reject);
void _putss(char *str);
int _atoi(char *str);


int execmd(char **argv);
char *get_path(char *cmd);

char **parser(char *lineptr);


/* free.c */
void free_memory_p(char *ptr);
void free_memory_pp(char **ptr);

/**
 * struct builtins - builtins data type
 * @name: command name
 * @func: function pointer to command
 */


typedef struct builtins
	{
		char *name;
		int (*func)(char **, int, char *);
	} builtins;
int _env(char **cmd, int status, char *filename);
int __exit(char **cmd, int status, char *filename);
int _cd(char **argv, int argc, char *filename);


char *_getenv(const char *name);
#endif
