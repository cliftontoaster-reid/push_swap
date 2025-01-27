/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:34:24 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/23 15:07:31 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nbr.h"

/// @brief Returns a number from a list at a given index.
/// @param lst the list to get the number from.
/// @param index the index of the number to return.
/// @return A pointer to the number at the given index
///          or NULL if the index is out of range.
int	*ilst_get(t_list *lst, int index)
{
	int	i;

	if (!lst || index < 0)
		return (NULL);
	if (index == 0)
		return ((int *)lst->content);
	i = 0;
	while (lst && i < index)
	{
		lst = lst->next;
		i++;
	}
	if (i == index)
		return ((int *)lst->content);
	return (NULL);
}

/// @brief Find and return the index of a number in a list.
/// @param lst the list to search.
/// @param value the number to find.
/// @return The index of the number in the list or -1 if not found.
int	ilst_find(t_list *lst, int value)
{
	int	i;

	if (!lst)
		return (-1);
	i = 0;
	while (lst)
	{
		if (*(int *)lst->content == value)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}
