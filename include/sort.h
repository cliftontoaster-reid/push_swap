/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:11:51 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/28 16:05:20 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "data.h"

void	brot_push(t_human *data);
void	nofree(void *content);

/// @brief Moves a number within the stack to a specified index.
///
/// @details
/// This function locates the index of `nbr` in stack `data->a` and determines
/// if it needs to be moved to the provided index `idx`. If the number is not
/// found or is already at the target index, the function returns without
/// performing any action. Otherwise, it calculates the necessary offset and
/// calls `move_offset` to perform the movement within the stack.
///
/// @param data Pointer to the data structure containing stack information.
/// @param stack The identifier of the stack (e.g., 0 for stack A,
///               1 for stack B).
/// @param nbr The number to move within the stack.
/// @param idx The target index to move the number to.
void	move(t_human *data, int stack, int nbr, int idx);

#endif
