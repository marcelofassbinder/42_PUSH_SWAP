/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:35:35 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/06 19:45:04 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ra(t_stack **stack_a, bool print)
{
	t_stack	*last;

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

void	rotate_rb(t_stack **stack_b, bool print)
{
	t_stack	*last;

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

void	rotate_rr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	rotate_ra(stack_a, false);
	rotate_rb(stack_b, false);
	if (print)
		ft_printf("rr\n");
}
