/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:06:55 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/17 21:07:33 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	if (!check_input(argc, argv))
		return (ft_printf("Error\n"));
	init_stack(&a, argv);
	print_stack(&a);
	rotate_ra(&a);
	ft_printf("-- teste ra --\n");
	print_stack(&a);

/* 	if (stack_size(&a) == 2)
	{
		if (!stack_is_sorted(&a))
		{
			swap_sa(&a);
			exit (0);
		}
		return(0);
	} */
}
