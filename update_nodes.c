/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:52:34 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/27 17:10:04 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_nodes(t_stack_node **stack_a, t_stack_node **stack_b, char c)
{
	set_index(stack_a);
	set_index(stack_b);
	if (c == 'a')
		find_target_a(stack_a, stack_b);
	else
		find_target_b(stack_a, stack_b);
	set_cost(stack_a, stack_b);
}

void	check_decrease_cost(t_stack_node *tmp, t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (tmp->above_med && tmp->target->above_med)
	{
		if (tmp->index < tmp->target->index)
			tmp->cost -= tmp->index;
		else
			tmp->cost -= tmp->target->index;
	}
	else if (!(tmp->above_med) && !(tmp->target->above_med))
	{
		if (stack_size(stack_a) - tmp->index < stack_size(stack_b) - tmp->target->index)
			tmp->cost -= stack_size(stack_a) - tmp->index;
		else
			tmp->cost -= stack_size(stack_b) - tmp->target->index;
	}
}

void	set_cost(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*tmp;

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
		check_decrease_cost(tmp, stack_a, stack_b);
		tmp = tmp->next;
	}
}

void	set_index(t_stack_node **stack)
{
	t_stack_node	*tmp;
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

void	find_target_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node 	*tmp_a;
	t_stack_node 	*tmp_b;
	t_stack_node 	*target_node;
	int				target;

	tmp_a = *stack_a;
	while(tmp_a)
	{
		target = INT_MIN;
		tmp_b = *stack_b;
		while(tmp_b)
		{
			if(tmp_b->number < tmp_a->number && tmp_b->number > target)
			{	
				target = tmp_b->number;
				target_node = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (target == INT_MIN)
			tmp_a->target = find_biggest(stack_b);
		else
			tmp_a->target = target_node;
		tmp_a = tmp_a->next;
	}
}


