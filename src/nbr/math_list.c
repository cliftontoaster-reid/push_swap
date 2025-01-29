/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:50:50 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/28 17:21:33 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nbr.h"

int	ilst_max(t_list *lst)
{
	int	max;

	if (!lst)
		return (0);
	max = *(int *)lst->content;
	while (lst)
	{
		if (*(int *)lst->content > max)
			max = *(int *)lst->content;
		lst = lst->next;
	}
	return (max);
}

int	ilst_min(t_list *lst)
{
	int	min;

	if (!lst)
		return (0);
	min = *(int *)lst->content;
	while (lst)
	{
		if (*(int *)lst->content < min)
			min = *(int *)lst->content;
		lst = lst->next;
	}
	return (min);
}

int	ilst_sorted(t_list *lst)
{
	int	*nbr;
	int	*pre;

	if (!lst)
		return (1);
	while (lst->next)
	{
		pre = (int *)lst->content;
		nbr = (int *)lst->next->content;
		if (*nbr < *pre)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ilst_sorted_desc(t_list *lst)
{
	int	*nbr;
	int	*pre;

	if (!lst)
		return (1);
	while (lst->next)
	{
		nbr = (int *)lst->content;
		pre = (int *)lst->next->content;
		if (*nbr <= *pre)
			return (0);
		lst = lst->next;
	}
	return (1);
}
