/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:44:18 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/26 13:49:28 by mfassbin         ###   ########.fr       */
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

int	free_error(int argc, char **argv)
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
	ft_printf("Error\n");
	return (0);
}

/* 
int main(int argc, char **argv)
{
	ft_printf("%i", check_input(argc, argv));
} */