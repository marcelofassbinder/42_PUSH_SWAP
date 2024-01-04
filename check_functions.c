/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:44:18 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/04 00:05:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(char **input, long n)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (input[i] != NULL)
	{
		if (ft_atoi(input[i]) == n)
			c++;
		if (c == 2)
			return (0);
		i++;
	}
	return (1);
}

int	check_digit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-' && *str != '+')
			return (0);
		str++;
	}
	return (1);
}

int	check_input(char **argv)
{
	int			i;
	long long	n;
	
	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (0);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN || 
			!check_double(argv, n) || !check_digit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	free_split(int argc, char **argv, bool error)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	if (error)
		ft_printf("Error\n");
	return (0);
}

void	check_decrease_cost(t_stack_node *tmp, t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (tmp->above_med && tmp->target->above_med)
	{
		if (tmp->index < tmp->target->index)
			tmp->cost -= tmp->index;
		else
			tmp->cost -= tmp->target->index;
	}
	else if (!(tmp->above_med) && !(tmp->target->above_med))
	{
		if (stack_size(stack_a) - tmp->index < stack_size(stack_b) - tmp->target->index)
			tmp->cost -= stack_size(stack_a) - tmp->index;
		else
			tmp->cost -= stack_size(stack_b) - tmp->target->index;
	}
}
