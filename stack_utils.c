/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:33:55 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/17 21:40:49 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (stack == NULL)
		ft_printf("NULL");
	else
	{
		tmp = *stack;
		while(tmp)
		{
			ft_printf("%i\n", tmp->number);
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
	while(tmp)
	{
		if (tmp->next && tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
