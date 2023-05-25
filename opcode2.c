#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @value: The value to be pushed.
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = create_node(value);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->next = *stack;
	*stack = new_node;
}

/**
 * create_node - Creates a new node for the stack.
 * @value: The value to be stored in the node.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */
stack_t *create_node(int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->next = NULL;

	return (new_node);
}



/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: Double pointer to the head of the stack.
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 */
void pint(stack_t **stack)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 */
void pop(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	free(temp);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 */
void swap(stack_t **stack)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

