#include "monty.h"
/**
 * add_end_node - adds new node to the end
 * of the stack.
 * @stack: pointer to the stack
 * @n: integer value
 * Return: 0 Always on success, -1 on failure
int add_end_node(stack_t **stack, int n)
{
stack_t *new = NULL;

new = malloc(sizeof(stack_t));
if (new == NULL)
{
printf("Error: malloc failed");
return (-1);
}

new->n = n;
new->next = NULL;

if (*stack == NULL)
{
new->prev = NULL;
*stack = new;
}
else
{
new->prev = *stack;
(*stack)->next = new;
*stack = new;
}

return (0);
} */

int add_end_node(stack_t **h, int n)
{
	stack_t *new;

	if (!h)
		return (-1);

	/* malloc and set new node data */
	new = malloc(sizeof(struct stack_s));
	if (!new)
	{
		printf("Error: malloc failed");
		return (-1);
	}
	new->n = n;

	/* account for empty linked list */
	if (*h == NULL)
	{
		*h = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else /* insert to front */
	{
		new->next = *h;
		(*h)->prev = new;
		*h = new;
	}
	return (0);
}

/**
 * delete_end_node - deletes node at end of doubly linked list
 * @h: pointer to head of doubly linked list
 */
void delete_end_node(stack_t **h)
{
	stack_t *del = NULL;

	/* account for only one node in list */
	del = *h;
	if ((*h)->next == NULL)
	{
		*h = NULL;
		free(del);
	}
	else /* else delete front, and link correctly */
	{
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(del);
	}
}
