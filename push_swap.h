/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:01:50 by mfassbin          #+#    #+#             */
/*   Updated: 2023/12/27 17:10:33 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf/ft_printf.h"
#include <limits.h>
#include <stdbool.h>

// stack node structure 
typedef struct s_stack
{	
	struct s_stack 	*prev;
	struct s_stack 	*next;
	struct s_stack 	*target;
	int 			number;
	int				index;
	int				cost;
	bool			above_med;
}					t_stack_node;

// verifying args
int				check_input(char **argv);
int 			check_digit(char *str);
int 			check_double(char **input, long n);
int				count_words(const char *s, char c);

//creating and adding nodes
void			init_stack(t_stack_node **a, char **argv);
void			append_node(t_stack_node **stack, int number, bool head);

//stack utils
t_stack_node	*find_last_node(t_stack_node *stack);
t_stack_node	*find_biggest(t_stack_node **stack);
t_stack_node	*find_low(t_stack_node **stack);
void			print_stack(t_stack_node **stack);
int				stack_size(t_stack_node **stack);
int				stack_is_sorted(t_stack_node **stack);

//free functions
void			free_stack(t_stack_node **stack);
int				free_error(int argc, char **argv);

//swap first and second number
void			swap_sa(t_stack_node **stack_a, bool print);
void			swap_sb(t_stack_node **stack_b, bool print);
void			swap_ss(t_stack_node **stack_a, t_stack_node **stack_b);

//rotate top number to bottom of the stack
void			rotate_ra(t_stack_node **stack_a, bool print);
void			rotate_rb(t_stack_node **stack_b, bool print);
void			rotate_rr(t_stack_node **stack_a, t_stack_node **stack_b);

//rotate bottom number to top of the stack 
void			rotate_rra(t_stack_node **stack_a, bool print);
void			rotate_rrb(t_stack_node **stack_b, bool print);
void			rotate_rrr(t_stack_node **stack_a, t_stack_node **stack_b);

//push from stack_a to stack_b
void			push_pb(t_stack_node **stack_a, t_stack_node **stack_b);

//push from stack_b to stack_a
void			push_pa(t_stack_node **stack_b, t_stack_node **stack_a);

//turkey algorithm
void			algorithm(t_stack_node **stack_a, t_stack_node **stack_b);
void			prep_for_push(t_stack_node **stack, t_stack_node *target, char c);
void			move_a_to_b(t_stack_node **stack_a, t_stack_node **stack_b);
void			move_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_three(t_stack_node **stack);

//update data
void			update_nodes(t_stack_node **stack_a, t_stack_node **stack_b, char c);
void			set_index(t_stack_node **stack);
void			find_target_a(t_stack_node **stack_a, t_stack_node **stack_b);
void			find_target_b(t_stack_node **stack_a, t_stack_node **stack_b);
void			set_cost(t_stack_node **stack_a, t_stack_node **stack_b);
void			check_decrease_cost(t_stack_node *tmp, t_stack_node **stack_a, t_stack_node **stack_b);
t_stack_node	*find_cheapest(t_stack_node **stack);

#endif