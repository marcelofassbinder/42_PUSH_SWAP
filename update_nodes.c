/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:52:34 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/26 16:49:32 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_nodes(t_stack_node **stack_a, t_stack_node **stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	find_target(stack_a, stack_b);
	set_cost(stack_a, stack_b);
}

t_stack_node	*find_cheapest(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*cheapest;

	tmp = *stack;
	cheapest = tmp;
	while(tmp)
	{
		if (tmp->cost < cheapest->cost)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return(cheapest);
}

void	set_cost(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*tmp;

	tmp = *stack_a;
	while(tmp)
	{
		tmp->cost = tmp->index;
		if (!tmp->above_med)
			tmp->cost = stack_size(stack_a) - tmp->index;
		if (tmp->target->above_med)
			tmp->cost+= tmp->target->index;
		else
			tmp->cost += stack_size(stack_b) - tmp->target->index;
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

void	find_target(t_stack_node **stack_a, t_stack_node **stack_b)
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
		//ft_printf("number: %i, target: %i\n", tmp_a->number, tmp_a->target->number);
		tmp_a = tmp_a->next;
	}
}


