#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_MODE 0
#define QUEUE_MODE 1

#ifdef __cplusplus
extern "C"
{
#endif

	/* Function declarations */
	void pop(stack_t **stack);
	void pall(stack_t **stack);
	void pint(stack_t **stack);
	void swap(stack_t **stack);
	void add(stack_t **stack);
	void nop(stack_t **stack);

#ifdef __cplusplus
}
#endif


/* Structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

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
void divide(stack_t **stack);
void mul(stack_t **stack);
void mod(stack_t **stack);
void pchar(stack_t **stack);
void pstr(stack_t **stack);
void rotl(stack_t **stack);
void rotr(stack_t **stack);

/* Stack and Queue mode handling */
void stack_mode(stack_t **stack);
void queue_mode(stack_t **stack);

/* Helper Functions */
void comments(stack_t **stack);
int is_integer(char *str);
void free_stack(stack_t *stack);
size_t stack_len(stack_t *stack);
stack_t *create_node(int value);

#endif /* MONTY_H */
