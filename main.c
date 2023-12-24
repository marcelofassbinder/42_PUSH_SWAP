/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:06:55 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/23 23:36:44 by marvin           ###   ########.fr       */
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
	if (!check_input(argv))
		return (free_error(argc, argv, true));
	init_stack(&a, argv);
	ft_printf("stack a: \n");
	print_stack(&a);
	if (!stack_is_sorted(&a))
	{
		if (stack_size(&a) == 2)
			swap_sa(&a, true);
		else if (stack_size(&a) == 3)
			sort_three(&a);
	}
	ft_printf("stack a: \n");
	print_stack(&a);
	ft_printf("stack b: \n");
	print_stack(&b);
	free_stack(&a);
	free_stack(&b);
	free_error(argc, argv, false);
}
