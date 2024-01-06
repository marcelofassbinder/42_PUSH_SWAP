/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:35:17 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/06 19:58:57 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_sa(t_stack **stack_a, bool print)
{
	t_stack	*second;

	if (*stack_a == NULL)
		return ;
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

void	swap_sb(t_stack **stack_b, bool print)
{
	t_stack	*second;

	if (*stack_b == NULL)
		return ;
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

void	swap_ss(t_stack **stack_a, t_stack **stack_b, bool print)
{
	swap_sa(stack_a, false);
	swap_sa(stack_b, false);
	if (print)
		ft_printf("ss\n");
}
