/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rizz_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:10:27 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/22 13:11:40 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rra(t_list **a)
{
	t_list	*penultimate;
	t_list	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	penultimate = *a;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	last = penultimate->next;
	penultimate->next = NULL;
	last->next = *a;
	*a = last;
}

void	rrb(t_list **b)
{
	t_list	*penultimate;
	t_list	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	penultimate = *b;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	last = penultimate->next;
	penultimate->next = NULL;
	last->next = *b;
	*b = last;
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
