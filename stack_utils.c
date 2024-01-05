/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:33:55 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/05 19:41:14 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL)
		ft_printf("NULL\n");
	else
	{
		tmp = *stack;
		while (tmp)
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

int	stack_size(t_stack **stack)
{
	t_stack		*tmp;
	int			size;

	tmp = *stack;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	stack_is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
