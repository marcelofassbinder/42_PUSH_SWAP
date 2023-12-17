/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:35:17 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/17 21:40:24 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_sa(t_stack_node **stack_a)
{
	t_stack_node 	*tmp;
	int				swap;

	tmp = *stack_a;
	swap = tmp->number;
	tmp->number = tmp->next->number;
	tmp->next->number = swap;
}

void	swap_sb(t_stack_node **stack_b)
{
	t_stack_node 	*tmp;
	int				swap;

	tmp = *stack_b;
	swap = tmp->number;
	tmp->number = tmp->next->number;
	tmp->next->number = swap;
}
void	swap_ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap_sa(stack_a);
	swap_sa(stack_b);
}

