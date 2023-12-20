/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:54:39 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/20 17:12:38 by mfassbin         ###   ########.fr       */
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