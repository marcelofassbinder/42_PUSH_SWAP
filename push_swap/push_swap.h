/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:01:50 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/13 22:00:58 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf/ft_printf.h"
#include <limits.h>

// stack node structure 
typedef struct s_stack
{	
	int 			number;
	struct s_stack 	*prev;
	struct s_stack 	*next;
}					t_stack_node;

// verifying args
int				check_input(int argc, char **argv);
int 			check_digit(char *str);
int 			check_double(char **input, long n);

//manipulating stack
void			init_stack(t_stack_node **a, char **argv);
void			append_node(t_stack_node **stack, int number);
t_stack_node	*find_last_node(t_stack_node *stack);


#endif