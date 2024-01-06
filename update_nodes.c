/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:52:34 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/06 15:40:39 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_nodes(t_stack **stack_a, t_stack **stack_b, char c)
{
	set_index(stack_a);
	set_index(stack_b);
	if (c == 'a')
	{
		find_target_a(stack_a, stack_b);
		set_cost_a(stack_a, stack_b);
	}
	else
	{
		find_target_b(stack_a, stack_b);
		set_cost_b(stack_a, stack_b);
	}
}

void	find_target_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack			*tmp_a;
	t_stack			*tmp_b;
	t_stack			*target_node;
	long			target;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		target = -2147483649;
		tmp_b = *stack_b;
		while (tmp_b)
		{
			if (tmp_b->number < tmp_a->number && tmp_b->number > target)
			{
				target = tmp_b->number;
				target_node = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (target == -2147483649)
			tmp_a->target = find_biggest(stack_b);
		else
			tmp_a->target = target_node;
		tmp_a = tmp_a->next;
	}
}

void	find_target_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;
	t_stack		*target_node;
	long		target;

	tmp_b = *stack_b;
	while (tmp_b)
	{
		target = 2147483648;
		tmp_a = *stack_a;
		while (tmp_a)
		{
			if (tmp_a->number > tmp_b->number && tmp_a->number < target)
			{
				target = tmp_a->number;
				target_node = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (target == 2147483648)
			tmp_b->target = find_low(stack_a);
		else
			tmp_b->target = target_node;
		tmp_b = tmp_b->next;
	}
}
