/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:33:55 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/27 17:43:17 by mfassbin         ###   ########.fr       */
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

t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while(stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	print_stack(t_stack_node **stack)
{
	t_stack_node *tmp;

	if (*stack == NULL)
		ft_printf("NULL");
	else
	{
		tmp = *stack;
		while(tmp)
		{
			ft_printf("number:%i -- ", tmp->number);
			ft_printf("index:%i -- ", tmp->index);
			ft_printf("above med?%i -- ", tmp->above_med);
			ft_printf("cost to push: %i\n", tmp->cost);
			if (tmp->target)
				ft_printf("target node:%i\n", tmp->target->number);
			tmp = tmp->next;
		}
	}
}

int	stack_size(t_stack_node **stack)
{
	t_stack_node 	*tmp;
	int 			size;

	tmp = *stack;
	size = 0;
	while(tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return(size);
}

int	stack_is_sorted(t_stack_node **stack)
{
	t_stack_node	*tmp;

	tmp = *stack;
	while(tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
