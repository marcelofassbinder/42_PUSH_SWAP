/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:52:36 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/06 21:12:22 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_output(t_stack **stack_a, t_stack **stack_b)
{	
	if (stack_is_sorted(stack_a) && *stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(stack_a);
	free_stack(stack_b);
}

void	free_error(char *command, t_stack **stack_a, t_stack **stack_b)
{	
	free(command);
	free_stack(stack_a);
	free_stack(stack_b);
	ft_printf("Error\n");
	exit(1);
}

int	ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while(str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return(0);
}

void	exec_command(char *command, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(command, "pa\n") == 0)
		push_pa(stack_b, stack_a, false);
	else if (ft_strcmp(command, "pb\n") == 0)
		push_pb(stack_a, stack_b, false);
	else if (ft_strcmp(command, "sa\n") == 0)
		swap_sa(stack_a, false);
	else if (ft_strcmp(command, "sb\n") == 0)
		swap_sb(stack_b, false);
	else if (ft_strcmp(command, "ss\n") == 0)
		swap_ss(stack_a, stack_b, false);
	else if (ft_strcmp(command, "ra\n") == 0)
		rotate_ra(stack_a, false);
	else if (ft_strcmp(command, "rb\n") == 0)
		rotate_rb(stack_b, false);
	else if (ft_strcmp(command, "rr\n") == 0)
		rotate_rr(stack_a, stack_b, false);
	else if (ft_strcmp(command, "rra\n") == 0)
		rotate_rra(stack_a, false);
	else if (ft_strcmp(command, "rrb\n") == 0)
		rotate_rrb(stack_b, false);
	else if (ft_strcmp(command, "rrr\n") == 0)
		rotate_rrr(stack_a, stack_b, false);
	else
		free_error(command, stack_a, stack_b);

}

void	read_command(t_stack **stack_a, t_stack **stack_b)
{
	char	*command;

	command = NULL;
	while(1)
	{
		command = get_next_line(0);
		if(command == NULL || ft_strcmp(command, "\n") == 0)
		{
			free(command);
			break;
		}
		exec_command(command, stack_a, stack_b);
		free(command);
	}
}
