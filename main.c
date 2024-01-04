/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:06:55 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/04 00:35:15 by marvin           ###   ########.fr       */
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
		return (free_split(argc, argv, true));
	init_stack(&a, argv);
	if (!stack_is_sorted(&a))
		algorithm(&a, &b);
	if (argc == 2)
		free_split(argc, argv, false);
	free_stack(&a);
	free_stack(&b);
}
