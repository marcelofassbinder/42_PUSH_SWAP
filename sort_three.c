/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:54:39 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/18 18:47:02 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stack_node **stack)
{
	t_stack_node	*tmp;

	tmp = *stack;
	if (find_biggest(stack) == tmp->number)
		rotate_ra(stack);	
	else if (find_biggest(stack) == tmp->next->number)
		rotate_rra(stack);
	
}