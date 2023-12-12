/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:01:50 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/12 22:30:19 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf/ft_printf.h"
#include <limits.h>

typedef struct s_stack
{	
	int 			number;
	struct s_stack 	*prev;
	struct s_stack 	*next;
}					t_stack;
int		check_input(int argc, char **argv);
int 	check_digit(char *str);
int 	check_double(char **input, long n);
void	init_stack(t_stack **a, char **argv);


#endif