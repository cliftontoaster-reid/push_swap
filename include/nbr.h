/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:46:22 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/25 11:30:25 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NBR_H
# define NBR_H

# include "libft.h"

int	ilst_max(t_list *lst);
int	ilst_min(t_list *lst);
int	ilst_sorted(t_list *lst);
int	ilst_sorted_desc(t_list *lst);

/// @brief Returns a number from a list at a given index.
/// @param lst the list to get the number from.
/// @param index the index of the number to return.
/// @return A pointer to the number at the given index
///          or NULL if the index is out of range.
int	*ilst_get(t_list *lst, int index);
/// @brief Find and return the index of a number in a list.
/// @param lst the list to search.
/// @param value the number to find.
/// @return The index of the number in the list or -1 if not found.
int	ilst_find(t_list *lst, int value);

#endif
