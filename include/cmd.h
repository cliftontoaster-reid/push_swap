/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:53:11 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/03 14:10:57 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "data.h"

// Swap the top two elements of stack 'a'.
//
// Do nothing if there is only one or no elements.
void	sa(t_list **a, t_list **b);

// Swap the top two elements of stack 'b'.
//
// Do nothing if there is only one or no elements.
void	sb(t_list **a, t_list **b);

// sa and sb at the same time.
void	ss(t_list **a, t_list **b);

// Push the top element of 'b' onto stack 'a'.
//
// Do nothing if 'b' is empty.
void	pa(t_list **a, t_list **b);

// Push the top element of 'a' onto stack 'b'.
//
// Do nothing if 'a' is empty.
void	pb(t_list **a, t_list **b);

// Shift up all elements of stack 'a' by 1.
//
// The first element becomes the last one.
void	ra(t_list **a, t_list **b);

// Shift up all elements of stack 'b' by 1.
//
// The first element becomes the last one.
void	rb(t_list **a, t_list **b);

// ra and rb at the same time.
void	rr(t_list **a, t_list **b);

// Shift down all elements of stack 'a' by 1.
//
// The last element becomes the first one.
void	rra(t_list **a, t_list **b);

// Shift down all elements of stack 'b' by 1.
//
// The last element becomes the first one.
void	rrb(t_list **a, t_list **b);

// rra and rrb at the same time.
void	rrr(t_list **a, t_list **b);

#endif
