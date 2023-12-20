/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:35:17 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/20 17:03:18 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_sa(t_stack_node **stack_a, bool print)
{
	t_stack_node 	*tmp;
	int				swap;

	tmp = *stack_a;
	swap = tmp->number;
	tmp->number = tmp->next->number;
	tmp->next->number = swap;
	if (print)
		ft_printf("sa\n");
}

void	swap_sb(t_stack_node **stack_b, bool print)
{
	t_stack_node 	*tmp;
	int				swap;

	tmp = *stack_b;
	swap = tmp->number;
	tmp->number = tmp->next->number;
	tmp->next->number = swap;
	if (print)
		ft_printf("sb\n");	
}
void	swap_ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap_sa(stack_a, false);
	swap_sa(stack_b, false);
	ft_printf("ss\n");
}
