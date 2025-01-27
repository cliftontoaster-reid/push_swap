/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:01:55 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/22 13:11:20 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ra(t_list **a)
{
	t_list	*first;
	t_list	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	last->next = first;
	first->next = NULL;
}

void	rb(t_list **b)
{
	t_list	*first;
	t_list	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	last->next = first;
	first->next = NULL;
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}
