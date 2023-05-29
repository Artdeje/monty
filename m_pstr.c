#include "monty.h"
#include <ctype.h>

/**
 * m_pstr - prints string in stack up to null byte
 * @stack: pointer to head of stack
 * @line_number: line number of operation
 *
 * Return: nothing
 */

void m_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int ch;

	(void)line_number;

	temp = *stack;

	while (temp != NULL)
	{
		ch = temp->n;

		if (!isascii(ch) || ch == 0)
			break;

		putchar(ch);

		temp = temp->next;

		if (temp == *stack)
			break;
	}

	putchar('\n');
}
