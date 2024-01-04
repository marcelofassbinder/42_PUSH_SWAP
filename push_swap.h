/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:01:50 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/04 18:02:40 by mfassbin         ###   ########.fr       */
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
}					t_stack;

// verifying args
int				check_input(char **argv);
int 			check_digit(char *str);
int 			check_double(char **input, long n);

//creating and adding nodes
void			init_stack(t_stack **a, char **argv);
void			append_node(t_stack **stack, int number, bool head);

//stack utils
t_stack	*find_last_node(t_stack **stack);
t_stack	*find_biggest(t_stack **stack);
t_stack	*find_low(t_stack **stack);
void			print_stack(t_stack **stack);
int				stack_size(t_stack **stack);
int				stack_is_sorted(t_stack **stack);

//free functions
void			free_stack(t_stack **stack);
int				free_split(int argc, char **argv, bool error);

//swap first and second number
void			swap_sa(t_stack **stack_a, bool print);
void			swap_sb(t_stack **stack_b, bool print);
void			swap_ss(t_stack **stack_a, t_stack **stack_b);

//rotate top number to bottom of the stack
void			rotate_ra(t_stack **stack_a, bool print);
void			rotate_rb(t_stack **stack_b, bool print);
void			rotate_rr(t_stack **stack_a, t_stack **stack_b);

//rotate bottom number to top of the stack 
void			rotate_rra(t_stack **stack_a, bool print);
void			rotate_rrb(t_stack **stack_b, bool print);
void			rotate_rrr(t_stack **stack_a, t_stack **stack_b);

//push from stack_a to stack_b
void			push_pb(t_stack **stack_a, t_stack **stack_b);

//push from stack_b to stack_a
void			push_pa(t_stack **stack_b, t_stack **stack_a);

//turkey algorithm
void			algorithm(t_stack **stack_a, t_stack **stack_b);
void			prep_for_push(t_stack **stack, t_stack *target, char c);
void			move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void			move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void			sort_three(t_stack **stack);

//update data
void			update_nodes(t_stack **stack_a, t_stack **stack_b, char c);
void			set_index(t_stack **stack);
void			find_target_a(t_stack **stack_a, t_stack **stack_b);
void			find_target_b(t_stack **stack_a, t_stack **stack_b);
void			set_cost_a(t_stack **stack_a, t_stack **stack_b);
void			set_cost_b(t_stack **stack_a, t_stack **stack_b);
void			decrease_cost(t_stack *tmp, t_stack **a, t_stack **b);
t_stack			*find_cheapest(t_stack **stack);

#endif