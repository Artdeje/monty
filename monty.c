#include "monty.h"

/* Global variables */
char *data = NULL;
int mode = STACK_MODE;

/**
 * stack_mode - Sets the mode to stack (LIFO).
 * @stack: Double pointer to the head of the stack.
 */
void stack_mode(stack_t **stack)
{
	(void)stack;
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

/**
 * comments - Handles comments in the Monty file.
 * @stack: Double pointer to the head of the stack.
 */
void comments(stack_t **stack)
{
	(void)stack;
}

/**
 * is_integer - Checks if a string is a valid integer.
 * @str: The string to check.
 *
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int is_integer(char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (0);
	}

	if (*str == '-' || *str == '+')
	{
		str++;
	}

	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}

/**
 * free_stack - Frees a stack.
 * @stack: The stack to free.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/**
 * stack_len - Calculates the length of a stack.
 * @stack: The stack to calculate the length of.
 *
 * Return: The length of the stack.
 */
size_t stack_len(stack_t *stack)
{
	size_t len = 0;

	while (stack != NULL)
	{
		stack = stack->next;
		len++;
	}

	return (len);
}

/**
 * create_node - Creates a new stack node.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the newly created node.
 */
stack_t *create_node(int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}

