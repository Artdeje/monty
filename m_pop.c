#include "monty.h"

/**
 * m_pop - deletes top element off the stack
 * @stack: pointer to head of stack
 * @line_number: line number of operation
 *
 * Return: nothing
 */

void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pop = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't pop an empty stack\n",
			line_number);

		exit(EXIT_FAILURE);
	}

	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;

	if (var.stack_len != 1)
		*stack = (*stack)->next;

	else
		*stack = NULL;

	free(pop);
	var.stack_len--;
}
