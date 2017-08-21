#define STACK_OVERFLOW  -100
#define SACK_UNDERFLOW	-101
#define	OUT_OF_MEMORY	-102

#include <stdio.h>
#include <stdlib.h>

typedef struct 		node_tag
{
	int				value;
	struct node_tag	*next;

}					node_t;

void	push(node_t **head, int value)
{
	node_t *tmp = (node_t *)malloc(sizeof(node_t));
	if (tmp == NULL)
		exit(STACK_OVERFLOW);
	tmp->next = *head;
	tmp->value = value;
	*head = tmp;
}

int		pop(node_t **head)
{
	node_t		*out;
	int			value;

	if (*head == NULL)
		exit (SACK_UNDERFLOW);
	out = *head;
	*head = (*head)->next;
	value = out->value;
	free(out);
	return value;
}

int		peek(const node_t *head)
{
	if (head == NULL)
		exit(SACK_UNDERFLOW);
	return head->value;
}

void	print_stack(const node_t *head)
{
	printf("stack >");
	while (head)
	{
		printf("%d", head->value);
		head = head->next;
	}
}

int		get_size(const node_t *head)
{
	int size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return size;
}

void	main()
{
	int i;

	i = 0;
	node_t *head = NULL;
	while (i < 30)
	{
		push(&head, i);
		i++;
	}
	printf("size = %d\n",get_size(head));
	while (head)
	{
		printf("%d\n",peek(head));
		printf("%d\n",pop(&head));
	}

	return (0);
}