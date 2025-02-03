/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arc_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:07:49 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/03 13:32:14 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	(void)b;
	if (!a || !*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = *a;
	*a = tmp;
}

// Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	(void)a;
	if (!b || !*b || !(*b)->next)
		return ;
	last = *b;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = *b;
	*b = tmp;
}

// rra and rrb at the same time.
void	rrr(t_list **a, t_list **b)
{
	rra(a, b);
	rrb(a, b);
}
