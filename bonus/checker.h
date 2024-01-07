/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:26:15 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/07 14:53:58 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./get_next_line/get_next_line.h"
# include "../push_swap.h"

void	exec_command(char *command, t_stack **stack_a, t_stack **stack_b);
void	read_command(t_stack **stack_a, t_stack **stack_b);
void	checker_output(t_stack **stack_a, t_stack **stack_b);

#endif
