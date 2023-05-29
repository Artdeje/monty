#include "monty.h"

/**
 * m_pint - prints integers in stack or exit if empty
 * @stack: pointer to head of stack
 * @line_number: line number of operation
 *
 * Return: nothing
 */

void m_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't pint, stack empty\n",
			line_number);

		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->n);
}
