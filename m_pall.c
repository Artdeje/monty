#include "monty.h"

/**
 * m_pall - prints all values on stack
 * @stack: pointer to head of stack
 * @line_number: line number from file
 *
 * Return: nothing
 */

void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)(line_number);

	head = *stack;

	while (head != NULL)
	{
		printf("%d\n", head->n);

		head = head->next;

		if (head == *stack)
		{
			return;
		}
	}
}
