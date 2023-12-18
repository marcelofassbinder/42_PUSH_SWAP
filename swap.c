/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:35:17 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/18 15:00:38 by mfassbin         ###   ########.fr       */
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
	ft_printf("sa\n");
}

void	swap_sb(t_stack_node **stack_b)
{
	t_stack_node 	*tmp;
	int				swap;

	tmp = *stack_b;
	swap = tmp->number;
	tmp->number = tmp->next->number;
	tmp->next->number = swap;
	ft_printf("sb\n");	
}
void	swap_ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node 	*tmp_a;
	t_stack_node 	*tmp_b;
	int				swap_a;
	int				swap_b;

	tmp_a = *stack_a;
	swap_a = tmp_a->number;
	tmp_a->number = tmp_a->next->number;
	tmp_a->next->number = swap_a;
	tmp_b = *stack_b;
	swap_b = tmp_b->number;
	tmp_b->number = tmp_b->next->number;
	tmp_b->next->number = swap_b;
	ft_printf("ss\n");
	//swap_sa(stack_a);
	//swap_sa(stack_b);
}

