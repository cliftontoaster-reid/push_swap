/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:01:12 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/22 15:35:01 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/// @brief Push the first element of the stack b to the stack a.
/// @param a stack A.
/// @param b stack B.
void	pa(t_list **a, t_list **b)
{
	t_list	*first;

	if (!b || !*b)
		return ;
	first = *b;
	*b = first->next;
	first->next = *a;
	*a = first;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*first;

	if (!a || !*a)
		return ;
	first = *a;
	*a = first->next;
	first->next = *b;
	*b = first;
}
