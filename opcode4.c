#include "monty.h"

/* Global variables */

char *data = NULL;
int mode = STACK_MODE;

/**
 * rotl - Rotates the stack to the top.
 * @stack: Double pointer to the head of the stack.
 */
void rotl(stack_t **stack)
{
	stack_t *first = *stack;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	second = first->next;

	while (first->next != NULL)
		first = first->next;

	first->next = *stack;
	*stack = second;
	second->next = NULL;
}

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the head of the stack.
 */
void rotr(stack_t **stack)
{
	stack_t *first = *stack;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (first->next != NULL)
	{
		second = first;
		first = first->next;
	}

	second->next = NULL;
	first->next = *stack;
	*stack = first;
}

/**
 * stack_mode - Sets the mode to stack (LIFO).
 * @stack: Double pointer to the head of the stack.
 */
void stack_mode(stack_t **stack)
{
	(void)stack; /* Unused parameter */
	mode = STACK_MODE;
}

/**
 * queue_mode - Sets the mode to queue (FIFO).
 * @stack: Double pointer to the head of the stack.
 */
void queue_mode(stack_t **stack)
{
	(void)stack;
	mode = QUEUE_MODE;
}
