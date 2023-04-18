#include "main.h"



/**
 * free_memory_pp - Free a double pointer
 * @ptr: Double pointer to free
 */
void free_memory_pp(char **ptr)
{
	char **temp;

	for (temp = ptr; *temp != NULL; temp++)
	{
		free_memory_p(*temp);
	}

	free(ptr);
}


/**
 * free_memory_p - Free a pointer
 * @ptr: Pointer to free
 */


void free_memory_p(char *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}

	ptr = NULL;
}

/**
* _putss - To prints the values of string
* @str: The varible to hold the string
* Return: The strings
*/

void _putss(char *str)
{	int i = 0;
	while (str[i] != '\0')
	{	_putchar(str[i]);
	i++;
	}
}

/**
 * _strdup - function taht duplicate string
 * @s: the string to duplicate
 * Return: pointer to the new string
 */


char *_strdup(char *s)
{	char *new_string;
	int len;

	len = _strlen(s);
	new_string = malloc(len + 1);

	if (new_string == NULL)
	{
		return (NULL);
	}

	_strcpy(new_string, s);

	return (new_string);

}

/**
 * _atoi - function that convert string to integer
 * @str: The string to convert
 * Return: converted int
 */

int _atoi(char *str)
{
	int res = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1 - 2 * (str[i++] == '-');
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > MAX_INT / 10 || (res == MAX_INT / 10 && str[i] - '0' > 7))
		{
			if (sign == 1)
				return (MAX_INT);
			else
				return (MIN_INT);
		}
		res = 10 * res + (str[i++] - '0');
	}

	return (res * sign);
}

