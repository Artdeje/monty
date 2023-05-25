#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Double pointer to the head of the stack.
 */
void nop(stack_t **stack)
{
	(void)stack;
}

/**
 * pchar - Prints the char at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 */
void pchar(stack_t **stack)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
	putchar('\n');
}

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 */
void pstr(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL && current->n != 0 && (current->n >= 32 && current->n <= 127))
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}

