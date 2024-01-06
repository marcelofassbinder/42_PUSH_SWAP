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

t_stack	*find_biggest(t_stack **stack)
{
	t_stack	*big;
	t_stack	*tmp;

	tmp = *stack;
	big = tmp;
	while (tmp)
	{
		if (tmp->number > big->number)
			big = tmp;
		tmp = tmp->next;
	}
	return (big);
}

t_stack	*find_low(t_stack **stack)
{
	t_stack	*low;
	t_stack	*tmp;

	tmp = *stack;
	low = tmp;
	while (tmp)
	{
		if (tmp->number < low->number)
			low = tmp;
		tmp = tmp->next;
	}
	return (low);
}

t_stack	*find_last_node(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_stack	*find_cheapest(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*cheapest;

	tmp = *stack;
	cheapest = tmp;
	while (tmp)
	{
		if (tmp->cost < cheapest->cost)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}
