#include "monty.h"

/**
 * rotr - rotates stack to bottom
 * @stack: pointer to the begining of list
 * @line_number: line number of operation
 *
 * Return: nothing
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack)
		*stack = (*stack)->prev;
}
