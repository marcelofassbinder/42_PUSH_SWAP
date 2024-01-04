/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:55:32 by marvin            #+#    #+#             */
/*   Updated: 2023/12/29 22:55:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_biggest(t_stack_node **stack)
{
	t_stack_node	*big;
	t_stack_node	*tmp;

	tmp = *stack;
	big = tmp;
	while(tmp)
	{
		if (tmp->number > big->number)
			big = tmp;
		tmp = tmp->next;
	}
	return(big);
}

t_stack_node	*find_low(t_stack_node **stack)
{
	t_stack_node	*low;
	t_stack_node	*tmp;

	tmp = *stack;
	low = tmp;
	while(tmp)
	{
		if (tmp->number < low->number)
			low = tmp;
		tmp = tmp->next;
	}
	return(low);
}

t_stack_node	*find_last_node(t_stack_node **stack)
{
	t_stack_node	*tmp;

	tmp = *stack;
	if (tmp == NULL)
		return (NULL);
	while(tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_stack_node	*find_cheapest(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*cheapest;

	tmp = *stack;
	cheapest = tmp;
	while(tmp)
	{
		if (tmp->cost < cheapest->cost)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return(cheapest);
}
