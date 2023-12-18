/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:35:35 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/18 15:52:47 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ra(t_stack_node **stack_a)
{
	t_stack_node	*tmp;
	int				first;

	tmp = *stack_a;
	first = tmp->number;
	while(tmp->next)
	{
		tmp->number = tmp->next->number;
		tmp = tmp->next;
	}
	tmp->number = first;
	ft_printf("ra\n");
}

void	rotate_rb(t_stack_node **stack_b)
{
	t_stack_node	*tmp;
	int				first;

	tmp = *stack_b;
	first = tmp->number;
	while(tmp->next)
	{
		tmp->number = tmp->next->number;
		tmp = tmp->next;
	}
	tmp->number = first;
	ft_printf("rb\n");
}

void	rotate_rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*tmp_a;
	t_stack_node	*tmp_b;
	int				first_a;
	int				first_b;

	tmp_a = *stack_a;
	first_a = tmp_a->number;
	while(tmp_a->next)
	{
		tmp_a->number = tmp_a->next->number;
		tmp_a = tmp_a->next;
	}
	tmp_a->number = first_a;
	tmp_b = *stack_b;
	first_b = tmp_b->number;
	while(tmp_b->next)
	{
		tmp_b->number = tmp_b->next->number;
		tmp_b = tmp_b->next;
	}
	tmp_b->number = first_b;
	ft_printf("rr\n");
}