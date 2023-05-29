#include "monty.h"

/**
 * free_lineptr - frees line pointer
 * @status: exit status
 * @arg: pointer to line
 *
 * Return: noothing
 */

void free_lineptr(int status, void *arg)
{
	char **lineptr = arg;

	(void)status;
	
	if (*lineptr != NULL)
		free(*lineptr);
}
