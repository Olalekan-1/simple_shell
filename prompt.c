#include "main.h"


/**
 * prompt - To print prompt to the screen
 * @void: void
 * Return: void
 */


void prompt(void)
{
	char prompt[3] = {'$', ' ', '\0'};

	_putss(prompt);
	fflush(stdout);
}
