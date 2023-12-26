/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:06:55 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/26 20:06:09 by mfassbin         ###   ########.fr       */
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
		return (free_error(argc, argv));
	init_stack(&a, argv);
	if (!stack_is_sorted(&a))
	{
		if (stack_size(&a) == 2)
			swap_sa(&a, true);
		else if (stack_size(&a) == 3)
			sort_three(&a);
		else
			algorithm(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
}
