/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:01:01 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/18 15:41:59 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_rra(t_stack_node **stack_a)
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
	ft_printf("rra\n");
}

void	rotate_rrb(t_stack_node **stack_b)
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
	ft_printf("rrb\n");
}

void	rotate_rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*last_a;
	t_stack_node	*last_b;
	int				final_a;
	int				final_b;

	last_a = find_last_node(*stack_a);
	final_a = last_a->number;
	while(last_a->prev)
	{
		last_a->number = last_a->prev->number;
		last_a = last_a->prev;
	}
	last_a->number = final_a;

	last_b = find_last_node(*stack_b);
	final_b = last_b->number;
	while(last_b->prev)
	{
		last_b->number = last_b->prev->number;
		last_b = last_b->prev;
	}
	last_b->number = final_b;
	ft_printf("rrr\n");
	//rotate_rra(stack_a);
	//rotate_rrb(stack_b);
}
