/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretzel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:36:50 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/29 16:35:29 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pretzel.h"
#include "sort.h"
#include "utils.h"

int	pretzel(t_human *data)
{
	push_op(data, PB);
	push_op(data, PB);
	if (*ilst_get(data->b, 0) < *ilst_get(data->b, 1))
		push_op(data, SB);
	while (data->a)
	{
		brot_push(data);
		move(data, 1, ilst_max(data->b), 0);
	}
	while (data->b)
	{
		push_op(data, PA);
	}
	move(data, 0, ilst_min(data->a), 0);
	return (0);
}
