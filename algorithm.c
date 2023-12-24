/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:54:39 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/24 00:07:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*tmp;

	tmp = *stack;
	if (find_biggest(stack) == tmp)
		rotate_ra(stack, true);	
	else if (find_biggest(stack) == tmp->next)
		rotate_rra(stack, true);
	if (tmp->number > tmp->next->number)
		swap_sa(stack, true);
}

t_stack_node	*find_cheapest(t_stack_node **stack_a, t_stack_node **stack_b)
{
	
}

void	algorithm(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push_pb(stack_a, stack_b);
	push_pb(stack_a, stack_b);


	
}
