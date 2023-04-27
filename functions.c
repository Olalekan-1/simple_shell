#include "main.h"


/**
* _memcpy - To copy a memoery area
* @dest: The destination to copy to
* @src: The source to copy from
* @n: The n bytes to copy
* Return: to the destination the n bytes cpied from the src.
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{	unsigned int i = 0;
	for (i = 0; i < n; i++)
	{
	dest[i] = src[i];
	}
	return (dest);
}

/**
 * _strncmp - Function to compare len of 2 string
 * @s1: The first string
 * @s2: The second string
 * @n: The len of index to be compare
 * Return: the diffence if not equal else 0 if equal
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] == '\0')
		{
			return (0);
		}
	}

	return (0);
}

/**
 * is_numeric - to chec if sting is numbers
 * @str: string to check
 * Return: 0 for sucess
 */


int is_numeric(const char *str)
{	const char *c;

	for (c = str; *c != '\0'; c++)
	{
		if (*c < '0' || *c > '9')
		{
			return (0);
		}
	}
	return (1);
}

