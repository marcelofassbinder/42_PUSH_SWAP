/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:01:01 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/03 16:51:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_rra(t_stack_node **stack_a, bool print)
{
	t_stack_node	*last;

	last = find_last_node(stack_a);
	last->next = *stack_a;
	last->prev->next = NULL;
	(*stack_a)->prev = last;
	*stack_a = last;
	(*stack_a)->prev = NULL;
	if (print)
		ft_printf("rra\n");
}

void	rotate_rrb(t_stack_node **stack_b, bool print)
{
	t_stack_node	*last;

	last = find_last_node(stack_b);
	last->next = *stack_b;
	last->prev->next = NULL;
	(*stack_b)->prev = last;
	*stack_b = last;
	(*stack_b)->prev = NULL;
	if (print)
		ft_printf("rrb\n");
}

void	rotate_rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate_rra(stack_a, false);
	rotate_rrb(stack_b, false);
	ft_printf("rrr\n");
}