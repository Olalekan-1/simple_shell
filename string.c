#include "main.h"


/**
* _strcpy - To coppy a string from source to a destn.
* @src: The source return value;
* @dest: The destination return value.
* Return: 0 always sucess
*/

char *_strcpy(char *dest, char *src)
{	int i;
	for (i = 0; src[i] != '\0'; i++)
	{	dest[i] = src[i];
	}
	dest[i++] = '\0';
	return (dest);
}



/**
* _strlen - to check the length of a string
* @s: the variable to check from
* Return: the length of the string.
*/

int _strlen(char *s)
{	int i = 0;
	while (*s != '\0')
	{	i++;
	s++;
	}
	return (i);
}



/**
* _strcat - to concatenate two strings
* @dest: the destination to append
* @src: the source to be append
* Return: the new value of dest
*/

char *_strcat(char *dest, char *src)
{	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{	i++;
	}
	while (src[j] != '\0')
	{ dest[i] = src[j];
	i++;
	j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - comapare two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if equal else  value diff
 */


int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i]; i++)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

	return (0);
}



























