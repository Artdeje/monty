#include "monty.h"

/**
 * rotl - rotates stack
 * @stack: pointer to begining of list
 * @line_number: line number of operation
 *
 * Return: nothing
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack)
		*stack = (*stack)->next;
}
