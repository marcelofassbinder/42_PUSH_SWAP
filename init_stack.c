/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:24:03 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/27 17:08:00 by mfassbin         ###   ########.fr       */
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
	new->prev = NULL;
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

void	find_target_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node 	*tmp_a;
	t_stack_node 	*tmp_b;
	t_stack_node 	*target_node;
	int				target;

	tmp_b = *stack_b;
	while(tmp_b)
	{
		target = INT_MAX;
		tmp_a = *stack_a;
		while(tmp_a)
		{
			if(tmp_a->number > tmp_b->number && tmp_a->number < target)
			{	
				target = tmp_a->number;
				target_node = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (target == INT_MAX)
			tmp_b->target = find_low(stack_b);
		else
			tmp_b->target = target_node;
		tmp_b = tmp_b->next;
	}
}
void	move_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*target;

	target = (*stack_b)->target;
	while(*stack_a != target)
	{
		if (target->above_med)
			rotate_ra(stack_a, true);
		else
			rotate_rra(stack_a, true);
	}
	push_pa(stack_b, stack_a);
}