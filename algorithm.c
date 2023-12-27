/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:54:39 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/27 17:12:04 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*tmp;

	tmp = *stack;
	if (find_biggest(stack) == *stack)
		rotate_ra(stack, true);	
	else if (find_biggest(stack) == (*stack)->next)
		rotate_rra(stack, true);
	if ((*stack)->number > (*stack)->next->number)
		swap_sa(stack, true);
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

void	prep_for_push(t_stack_node **stack, t_stack_node *target, char c)
{
	while (*stack != target)
	{
		if (target->above_med)
		{
			if (c == 'a')
				rotate_ra(stack, true);
			else
				rotate_rb(stack, true);
		}
		else
		{
			if (c == 'a')
				rotate_rra(stack, true);
			else
				rotate_rrb(stack, true);
		}
	}
}

void	move_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheap;

	cheap = find_cheapest(stack_a);
	if (cheap->above_med && cheap->target->above_med)
		while(cheap != *stack_a && cheap->target != *stack_b)
			rotate_rr(stack_a, stack_b);
	else if (!(cheap->above_med) && !(cheap->target->above_med))
		while(cheap != *stack_a && cheap->target != *stack_b)
			rotate_rrr(stack_a, stack_b);
	prep_for_push(stack_a, cheap, 'a');
	prep_for_push(stack_b, cheap->target, 'b');
	push_pb(stack_a, stack_b);
}

void	algorithm(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (stack_size(stack_a) > 3)
		push_pb(stack_a, stack_b);
	if (stack_size(stack_a) > 3)
		push_pb(stack_a, stack_b);
	while(stack_size(stack_a) > 3 && !stack_is_sorted(stack_a))
	{
		update_nodes(stack_a, stack_b, 'a');
		ft_printf("stack a:\n");
		print_stack(stack_a);
		ft_printf("stack b:\n");
		print_stack(stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	ft_printf("stack a:\n");
	print_stack(stack_a);
	ft_printf("stack b:\n");
	print_stack(stack_b);
	while(*stack_b != NULL)
	{
		update_nodes(stack_a, stack_b, 'b');
		ft_printf("stack a:\n");
		print_stack(stack_a);
		ft_printf("stack b:\n");
		print_stack(stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	ft_printf("stack a:\n");
	print_stack(stack_a);
	ft_printf("stack b:\n");
	print_stack(stack_b);
}
