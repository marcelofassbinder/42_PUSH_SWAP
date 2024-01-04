/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:30:05 by marvin            #+#    #+#             */
/*   Updated: 2023/12/29 22:30:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while(tmp)
	{
		if (tmp->above_med)
			tmp->cost = tmp->index;
		if (!tmp->above_med)
			tmp->cost = stack_size(stack_a) - tmp->index;
		if (tmp->target->above_med)
			tmp->cost+= tmp->target->index;
		if (!(tmp->target->above_med))
			tmp->cost += stack_size(stack_b) - tmp->target->index;
		decrease_cost(tmp, stack_a, stack_b);
		tmp = tmp->next;
	}
}

void	set_cost_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	while(tmp)
	{
		if (tmp->above_med)
			tmp->cost = tmp->index;
		if (!tmp->above_med)
			tmp->cost = stack_size(stack_b) - tmp->index;
		if (tmp->target->above_med)
			tmp->cost+= tmp->target->index;
		if (!(tmp->target->above_med))
			tmp->cost += stack_size(stack_a) - tmp->target->index;
		decrease_cost(tmp, stack_b, stack_a);
		tmp = tmp->next;
	}
	
}

void	set_index(t_stack **stack)
{
	t_stack	*tmp;
	int				i;
	int				med;

	med = stack_size(stack) / 2;
	tmp = *stack;
	i = 0;
	while(tmp)
	{
		tmp->index = i;
		if (i < med)
			tmp->above_med = true;
		else
			tmp->above_med = false;
		i++;
		tmp = tmp->next;
	}
}