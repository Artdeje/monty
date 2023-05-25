#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Structures */

/**
 * struct stack_s - Represents a stack (or queue) data structure
 * @n: The value stored in the stack (or queue)
 * @next: Pointer to the next element in the stack (or queue)
 *
 * Description: This structure is used to implement a stack or queue
 * using a linked list.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *next;
} stack_t;

/* Function Prototypes */

/* Opcode Functions */
void push(stack_t **stack, int value);
void pall(stack_t **stack);
void pint(stack_t **stack);
void pop(stack_t **stack);
void swap(stack_t **stack);
void add(stack_t **stack);
void nop(stack_t **stack);
void sub(stack_t **stack);
void div(stack_t **stack);
void mul(stack_t **stack);
void mod(stack_t **stack);
void pchar(stack_t **stack);
void pstr(stack_t **stack);
void rotl(stack_t **stack);
void rotr(stack_t **stack);

/* Helper Functions */
int is_integer(char *str);
void free_stack(stack_t *stack);
size_t stack_len(stack_t *stack);
stack_t *create_node(int value);

#endif /* MONTY_H */
