/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:44:18 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/12 22:41:51 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_double(char **input, long n)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while(input[i] != NULL)
	{
		if(ft_atoi(input[i]) == n)
			c++;
		if (c == 2)
			return(0);
		i++;
	}
	return(1);
}

int check_digit(char *str)
{
	while(*str)
	{
		if(!ft_isdigit(*str))
			return(0);
		str++;
	}
	return(1);
}


int check_input(int argc, char **argv)
{
	char		**input;
	int 		i;
	long long	n;
	
	if (argc == 2)
		input = ft_split(argv[1], ' ');
	else
		input = argv + 1;
	i = 0;
	while(input[i])
	{
		n = ft_atoi(input[i]);
		if (n > INT_MAX || n < INT_MIN || !check_double(input, n) || !check_digit(input[i]))
			return(0);
		i++;
	}
	return(1);	
}
/* 
int main(int argc, char **argv)
{
	ft_printf("%i", check_input(argc, argv));
} */