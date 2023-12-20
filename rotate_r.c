/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:35:35 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/20 17:02:10 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ra(t_stack_node **stack_a, bool print)
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
	if (print)
		ft_printf("ra\n");
}

void	rotate_rb(t_stack_node **stack_b, bool print)
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
	if (print)
		ft_printf("rb\n");
}

void	rotate_rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate_ra(stack_a, false);
	rotate_rb(stack_b, false);
	ft_printf("rr\n");
}