/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:31:49 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/03 17:32:04 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

// Swaps the first 2 elements at the top of stack a.
//
// Does nothing if there is only one or no elements.
void	sa(t_list **a, t_list **b)
{
	void	*tmp;

	if (!a || !(*a) || !((*a)->next))
		return ;
	tmp = (*a)->content;
	(*a)->content = ((*a)->next)->content;
	((*a)->next)->content = tmp;
	(void)b;
}

// Swaps the first 2 elements at the top of stack b.
//
// Does nothing if there is only one or no elements.
void	sb(t_list **a, t_list **b)
{
	void	*tmp;

	if (!b || !(*b) || !((*b)->next))
		return ;
	tmp = (*b)->content;
	(*b)->content = ((*b)->next)->content;
	((*b)->next)->content = tmp;
	(void)a;
}

// sa and sb at the same time.
void	ss(t_list **a, t_list **b)
{
	sa(a, b);
	sb(a, b);
}
