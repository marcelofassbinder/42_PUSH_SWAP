/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:24:03 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/06 15:44:08 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack **stack, int number, bool head)
{
	t_stack	*new;
	t_stack	*tmp;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->number = number;
	new->next = NULL;
	new->prev = NULL;
	if (*stack == NULL)
		*stack = new;
	else if (head == false)
	{
		tmp = find_last_node(stack);
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

void	init_stack(t_stack **stack, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		n = ft_atoi(argv[i]);
		append_node(stack, (int)n, false);
		i++;
	}
	set_index(stack);
}

void	free_stack(t_stack **stack)
{
	t_stack	*old;

	while (*stack)
	{
		old = *stack;
		*stack = (*stack)->next;
		free(old);
	}
	free(*stack);
}

void	min_to_top(t_stack **stack_a)
{
	t_stack	*min;

	set_index(stack_a);
	min = find_low(stack_a);
	while (min != *stack_a)
	{
		if (min->above_med)
			rotate_ra(stack_a, true);
		else
			rotate_rra(stack_a, true);
	}
}
