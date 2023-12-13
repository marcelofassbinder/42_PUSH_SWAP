/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:33:55 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/13 22:16:35 by mfassbin         ###   ########.fr       */
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
void	append_node(t_stack_node **stack, int number)
{
	t_stack_node	*new;
	t_stack_node	*last;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		new->number = number;
		new->prev = NULL;
	}
	else
	{
		last = find_last_node(*stack);
		last->next = new;
		new->prev = last;
	}
	ft_printf("%i\n", new->number);
}
