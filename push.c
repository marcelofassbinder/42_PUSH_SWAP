/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:11:54 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/06 19:55:25 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_pb(t_stack **stack_a, t_stack **stack_b, bool print)
{
	t_stack	*old;

	if (*stack_a == NULL)
		return ;
	old = *stack_a;
	if (*stack_b == NULL)
	{
		append_node(stack_b, old->number, false);
		*stack_a = (*stack_a)->next;
		free(old);
		if (print)
			ft_printf("pb\n");
		return ;
	}
	append_node(stack_b, old->number, true);
	*stack_a = (*stack_a)->next;
	free(old);
	if (print)
		ft_printf("pb\n");
}

void	push_pa(t_stack **stack_b, t_stack **stack_a,  bool print)
{
	t_stack	*old;

	if (*stack_b == NULL)
		return ;
	old = *stack_b;
	if (*stack_a == NULL)
	{
		append_node(stack_a, old->number, false);
		*stack_b = (*stack_b)->next;
		free(old);
		if (print)
			ft_printf("pa\n");
		return ;
	}
	append_node(stack_a, old->number, true);
	*stack_b = (*stack_b)->next;
	free(old);
	if (print)
		ft_printf("pa\n");
}
