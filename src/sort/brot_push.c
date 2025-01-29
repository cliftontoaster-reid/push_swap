/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brot_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:09:35 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/29 16:31:08 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nbr.h"
#include "operations.h"
#include "sort.h"
#include "utils.h"

int	in_middle(t_human *data)
{
	t_list	*b;
	int		move;
	int		max;
	int		*new;

	move = 0;
	b = clone_list(data->b);
	max = ilst_max(data->b);
	while (*ilst_get(b, 0) != max)
	{
		rrb(&b);
		move--;
	}
	new = ilst_get(data->a, 0);
	if (new == NULL)
		return (0);
	while (*ilst_get(b, 0) > *new)
	{
		rb(&b);
		move++;
	}
	ft_lstclear(&b, nofree);
	return (move);
}

static void	move_offset(t_human *data, int stack, int offset)
{
	if (offset == 0)
		return ;
	if (offset > 0)
	{
		while (offset--)
		{
			if (stack == 0)
				push_op(data, RA);
			else
				push_op(data, RB);
		}
	}
	else
	{
		while (offset++)
		{
			if (stack == 0)
				push_op(data, RRA);
			else
				push_op(data, RRB);
		}
	}
}

void	move(t_human *data, int stack, int nbr, int idx)
{
	int	nbr_idx;

	if (stack == 0)
		nbr_idx = ilst_find(data->a, nbr);
	else
		nbr_idx = ilst_find(data->b, nbr);
	if (nbr_idx == -1 || nbr_idx == idx)
		return ;
	if (nbr_idx < idx)
		move_offset(data, stack, idx - nbr_idx);
	else
		move_offset(data, stack, idx + nbr_idx);
}

static void	owoooooooo(t_human *data, int m[2], int *top)
{
	int	uwu;

	if (m[1] < *top)
	{
		move(data, 0, ilst_max(data->a), 0);
		push_op(data, PB);
	}
	else if (*top < m[0])
	{
		move(data, 0, ilst_min(data->a), 0);
		push_op(data, PB);
	}
	else
	{
		uwu = in_middle(data);
		exec_offset(data, 1, uwu);
		push_op(data, PB);
	}
}

void	brot_push(t_human *data)
{
	int	*top;
	int	m[2];

	top = ilst_get(data->a, 0);
	m[1] = ilst_max(data->b);
	m[0] = ilst_min(data->b);
	owoooooooo(data, m, top);
}
