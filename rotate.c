/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:01:01 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/17 21:40:24 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ra(t_stack_node **stack_a)
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
}
void	rotate_rb(t_stack_node **stack_b)
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
}

void	rotate_rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate_ra(stack_a);
	rotate_rb(stack_b);
}
