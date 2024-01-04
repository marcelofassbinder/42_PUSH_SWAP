/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:35:17 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/04 00:17:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_sa(t_stack_node **stack_a, bool print)
{
	t_stack_node	*second;

	second = (*stack_a)->next;
	(*stack_a)->prev = second;
	(*stack_a)->next = second->next;
	if (stack_size(stack_a) >= 3)
		second->next->prev = *stack_a;
	second->prev = NULL;
	second->next = *stack_a;
	*stack_a = second;
	if (print)
		ft_printf("sa\n");
}

void	swap_sb(t_stack_node **stack_b, bool print)
{
	t_stack_node	*second;

	second = (*stack_b)->next;
	(*stack_b)->prev = second;
	(*stack_b)->next = second->next;
	if (stack_size(stack_b) >= 3)
		second->next->prev = *stack_b;
	second->prev = NULL;
	second->next = *stack_b;
	*stack_b = second;
	if (print)
		ft_printf("sb\n");
}
void	swap_ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap_sa(stack_a, false);
	swap_sa(stack_b, false);
	ft_printf("ss\n");
}
