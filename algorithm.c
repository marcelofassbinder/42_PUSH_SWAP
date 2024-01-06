/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:54:39 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/06 15:44:04 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	if (stack_size(stack) == 3)
	{
		if (find_biggest(stack) == *stack)
			rotate_ra(stack, true);
		else if (find_biggest(stack) == (*stack)->next)
			rotate_rra(stack, true);
		if ((*stack)->number > (*stack)->next->number)
			swap_sa(stack, true);
	}
}

void	prep_for_push(t_stack **stack, t_stack *target, char c)
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

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheap;

	cheap = find_cheapest(stack_a);
	if (cheap->above_med && cheap->target->above_med)
		while (cheap != *stack_a && cheap->target != *stack_b)
			rotate_rr(stack_a, stack_b);
	else if (!(cheap->above_med) && !(cheap->target->above_med))
		while (cheap != *stack_a && cheap->target != *stack_b)
			rotate_rrr(stack_a, stack_b);
	prep_for_push(stack_a, cheap, 'a');
	prep_for_push(stack_b, cheap->target, 'b');
	push_pb(stack_a, stack_b);
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheap;

	cheap = find_cheapest(stack_b);
	prep_for_push(stack_b, cheap, 'b');
	prep_for_push(stack_a, cheap->target, 'a');
	push_pa(stack_b, stack_a);
}

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(stack_a) == 2)
		swap_sa(stack_a, true);
	if (stack_size(stack_a) == 3)
		sort_three(stack_a);
	if (stack_size(stack_a) > 3)
		push_pb(stack_a, stack_b);
	if (stack_size(stack_a) > 3)
		push_pb(stack_a, stack_b);
	while (stack_size(stack_a) > 3)
	{
		update_nodes(stack_a, stack_b, 'a');
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b != NULL)
	{
		update_nodes(stack_a, stack_b, 'b');
		move_b_to_a(stack_a, stack_b);
	}
	min_to_top(stack_a);
}
	/* ft_printf("stack a:\n");
	print_stack(stack_a);
	ft_printf("stack b:\n");
	print_stack(stack_b); */
