#include "main.h"



/**
*  _putchar - writes the character to c to stdout
* @c: The character to print
* Return: on sucess 1.
* on error, -1 is returned, and error is set appropriately
*/
int _putchar(char c)
{       return(write(1, &c, 1));
}



/**
* _puts - To prints the values of string
* @str: The varible to hold the string
* Return: The strings
*/

void _puts(char *str)
{	int i = 0;
	while (str[i] != '\0')
	{	_putchar(str[i]);
	i++;
	}
	_putchar(10);
}


/**
 * _strtok - function that parse string into token
 * @str: The string to be parse
 * @del: the string delimiter
 * Return: pointer to token
 */


char *_strtok(char *str, const  char *del)
{
	static char  *buffer;
	/*char *start;*/
	/*int i = 0;*/

	if (str == NULL)
	{
		str = buffer;
		if (str == NULL)
		{
			return (NULL);
		}
	}

	str += _strspn(str, del);
	if (*str == '\0')
	{
		buffer = NULL;
		return (buffer);
	}

	buffer = str + _strcspn(str, del);
	if (buffer[0] != '\0')
	{
		buffer[0] = '\0';
		buffer++;
	}
	else
	{
		buffer = NULL;
	}
	return (str);
}




/**
* _strspn - To print the len of the substring
* @s: pointer to string
* @accept: pointer to the substring
* Return: the length of the substring in s
*/
unsigned int _strspn(char *s, const char *accept)
{	int i = 0;
	int j, k;

	for (j = 0; s[j]; j++)
	{
	for (k = 0; accept[k]; k++)
	{
	if (s[j] == accept[k])
	{	i++;
	break;
	}
	else if (accept[k + 1] == '\0')
	{
	return (i);
	}
	}
	}
	return (i);
}


/**
* _strcspn - To print the len of the substring
* @s: pointer to string
* @reject: pointer to the substring
* Return: the length of the substring in s
*/



size_t _strcspn(char *s, const char *reject)
{	const char *p, *q;
	size_t count = 0;

	for (p = s; *p != '\0'; p++)
	{
		for (q = reject; *q != '\0'; q++)
		{
			if (*p == *q)
			{
				return (count);
			}
		}
		count++;
	}
	return (count);
}
