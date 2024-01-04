/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:35:17 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/04 16:14:25 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_sa(t_stack_node **stack_a, bool print)
{
	t_stack_node	*second;

	second = (*stack_a)->next;
	if (stack_size(stack_a) >= 3)
		second->next->prev = *stack_a;
	(*stack_a)->prev = second;
	(*stack_a)->next = second->next;
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
	if (stack_size(stack_b) >= 3)
		second->next->prev = *stack_b;
	(*stack_b)->prev = second;
	(*stack_b)->next = second->next;
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
