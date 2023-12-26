/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:24:03 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/26 15:34:49 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **stack, int number, bool head)
{
	t_stack_node	*new;
	t_stack_node	*tmp;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return ;
	new->number = number;
	new->next = NULL;
	if (*stack == NULL)
		*stack = new;
	else if (head == false)
	{
		tmp = find_last_node(*stack);
		tmp->next = new;
		new->prev = tmp;
	}
	else if (head == true)
	{
		tmp = *stack;
		new->next = tmp;
		tmp->prev = new;
		*stack = new;
	}
}

void init_stack(t_stack_node **stack, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while(argv[i])
	{
		n = ft_atoi(argv[i]);
		append_node(stack, (int)n, false);
		i++;
	}
	set_index(stack);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*old;

	while(*stack)
	{
		old = *stack;
		*stack = (*stack)->next;
		free(old);
	}
	free(*stack);
}