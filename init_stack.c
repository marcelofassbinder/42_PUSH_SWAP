/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:24:03 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/17 20:58:27 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **stack, int number)
{
	t_stack_node	*new;
	t_stack_node	*last;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return ;
	new->number = number;
	new->next = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		last = find_last_node(*stack);
		last->next = new;
		new->prev = last;
	}
}

void init_stack(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while(argv[i])
	{
		n = ft_atoi(argv[i]);
		append_node(a, (int)n);
		i++;
	}
}