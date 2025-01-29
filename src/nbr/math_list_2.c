/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_list_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:08:19 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/27 14:11:07 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nbr.h"

int	ilst_idxmax(t_list *lst)
{
	int	max;
	int	idx;

	if (!lst)
		return (-1);
	max = ilst_max(lst);
	idx = 0;
	while (lst)
	{
		if (*(int *)lst->content == max)
			return (idx);
		lst = lst->next;
		idx++;
	}
	return (-1);
}

int	ilst_idxmin(t_list *lst)
{
	int	min;
	int	idx;

	if (!lst)
		return (-1);
	min = ilst_min(lst);
	idx = 0;
	while (lst)
	{
		if (*(int *)lst->content == min)
			return (idx);
		lst = lst->next;
		idx++;
	}
	return (-1);
}
