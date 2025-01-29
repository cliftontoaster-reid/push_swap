/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:58:10 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/27 15:34:45 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "libft.h"

/// @brief Enumerates the possible operations that can be performed
///         on the stacks.
typedef enum e_op
{
	/// @brief Swap the first two elements at the top of stack A.
	SA,
	/// @brief Swap the first two elements at the top of stack B.
	SB,
	/// @brief Swap the first two elements at the top of both stacks.
	SS,
	/// @brief Push the first element at the top of stack A to stack B.
	PA,
	/// @brief Push the first element at the top of stack B to stack A.
	PB,
	/// @brief Rotate the stack A.
	RA,
	/// @brief Rotate the stack B.
	RB,
	/// @brief Rotate both stacks.
	RR,
	/// @brief Reverse rotate the stack A.
	RRA,
	/// @brief Reverse rotate the stack B.
	RRB,
	/// @brief Reverse rotate both stacks.
	RRR
}		t_op;

t_op	*clone_op(t_op op);

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif
