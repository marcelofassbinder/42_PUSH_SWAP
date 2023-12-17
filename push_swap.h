/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:01:50 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/17 21:36:33 by mfassbin         ###   ########.fr       */
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

//creating and adding nodes
void			init_stack(t_stack_node **a, char **argv);
void			append_node(t_stack_node **stack, int number);

//stack utils
t_stack_node	*find_last_node(t_stack_node *stack);
void			print_stack(t_stack_node **stack);
int				stack_size(t_stack_node **stack);
int				stack_is_sorted(t_stack_node **stack);

//swap stack
void			swap_sa(t_stack_node **stack_a);
void			swap_sb(t_stack_node **stack_b);
void			swap_ss(t_stack_node **stack_a, t_stack_node **stack_b);

//rotate stack
void			rotate_ra(t_stack_node **stack_a);
void			rotate_rb(t_stack_node **stack_b);
void			rotate_rr(t_stack_node **stack_a, t_stack_node **stack_b);

#endif