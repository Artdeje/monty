#include "monty.h"

/**
 * add_node - adds new node to linked list
 * @stack: pointer to beginning of linked list
 * @n: value to be added to new node
 *
 * Description: function will add node to either top of stack or end of queue
 *
 * Return: pointer to new node, or NULL
 */

stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	new->n = n;

	if (*stack == NULL)
	{
		new->prev = new;
		new->next = new;
	}

	else
	{
		(*stack)->prev->next = new;
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
		new->next = *stack;
	}

	if (var.queue == STACK || var.stack_len == 0)
		*stack = new;

	return (new);
}
