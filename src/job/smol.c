/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:16:32 by lfiorell          #+#    #+#             */
/*   Updated: 2025/03/03 15:51:01 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "job.h"

static int	i(t_list *lst, int idx)
{
	int	*content;

	while (idx--)
		lst = lst->next;
	content = lst->content;
	return (*content);
}

void	sort_two(t_data *data)
{
	int	*a;
	int	*b;

	a = data->a->content;
	b = data->a->next->content;
	if (*a > *b)
		push_ops(data, &sa);
}

void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = i(data->a, 0);
	b = i(data->a, 1);
	c = i(data->a, 2);
	if (a > b && b < c && a < c)
		push_ops(data, &sa);
	else if (a > b && b > c)
	{
		push_ops(data, &ra);
		push_ops(data, &sa);
	}
	else if (a > b && b < c && a > c)
		push_ops(data, &ra);
	else if (a < b && b > c && a < c)
	{
		push_ops(data, &sa);
		push_ops(data, &ra);
	}
	else if (a < b && b > c && a > c)
		push_ops(data, &rra);
}

void	sort_four(t_data *data)
{
	int	new;
	int	min;

	push_ops(data, &pb);
	sort_three(data);
	new = i(data->b, 0);
	if (new < i(data->a, 0))
	{
		push_ops(data, &pa);
	}
	else if (new > i(data->a, 2))
	{
		push_ops(data, &pa);
		push_ops(data, &ra);
	}
	else
	{
		min = i(data->a, 0);
		while (i(data->a, 0) < new)
			push_ops(data, &ra);
		push_ops(data, &pa);
		while (i(data->a, 0) != min)
			push_ops(data, &rra);
	}
}
