/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:35:35 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/03 14:32:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ra(t_stack_node **stack_a, bool print)
{
	t_stack_node	*last;

	if (!(*stack_a) || (*stack_a)->next == NULL)
		return ;
	last = find_last_node(stack_a);
	(*stack_a)->prev = last;
	last->next = (*stack_a);
	(*stack_a)->next->prev = NULL;
	*stack_a = (*stack_a)->next;
	last->next->next = NULL;
	if (print)
		ft_printf("ra\n");
}

void	rotate_rb(t_stack_node **stack_b, bool print)
{
	t_stack_node	*last;

	if (!(*stack_b) || (*stack_b)->next == NULL)
		return ;
	last = find_last_node(stack_b);
	(*stack_b)->prev = last;
	last->next = (*stack_b);
	(*stack_b)->next->prev = NULL;
	*stack_b = (*stack_b)->next;
	last->next->next = NULL;
	if (print)
		ft_printf("rb\n");
}

void	rotate_rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate_ra(stack_a, false);
	rotate_rb(stack_b, false);
	ft_printf("rr\n");
}