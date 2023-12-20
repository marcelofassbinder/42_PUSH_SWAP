/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:01:01 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/20 17:02:33 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_rra(t_stack_node **stack_a, bool print)
{
	t_stack_node	*last;
	int				final;

	last = find_last_node(*stack_a);
	final = last->number;
	while(last->prev)
	{
		last->number = last->prev->number;
		last = last->prev;
	}
	last->number = final;
	if (print)
		ft_printf("rra\n");
}

void	rotate_rrb(t_stack_node **stack_b, bool print)
{
	t_stack_node	*last;
	int				final;

	last = find_last_node(*stack_b);
	final = last->number;
	while(last->prev)
	{
		last->number = last->prev->number;
		last = last->prev;
	}
	last->number = final;
	if (print)
		ft_printf("rrb\n");
}

void	rotate_rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate_rra(stack_a, false);
	rotate_rrb(stack_b, false);
	ft_printf("rrr\n");
}