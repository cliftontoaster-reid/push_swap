/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitshift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:02:14 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/10 21:49:49 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "job.h"
#include <limits.h>
#include <stdlib.h>

/*
** Returns the i-th bit of n.
*/
int	int_get_bit(int n, int i)
{
	return ((n >> i) & 1);
}

/*
** Returns the number of bits required to represent the maximum value
** in the list. If the list is empty, returns 0.
*/
int	get_max_bits(t_list *stack)
{
	int	max;
	int	max_bits;
	int	*num;

	if (stack == NULL)
		return (0);
	max = 0;
	while (stack)
	{
		num = stack->content;
		if (*num > max)
			max = *num;
		stack = stack->next;
	}
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/*
** Performs one iteration (for bit i) of the bitshift sort.
**
** Instead of traversing the list via a pointer that may become invalid when
** push_ops modifies the list,
	we first record the number of elements to process.
*/
void	bitshift_step(t_data *data, int i)
{
	int	count;
	int	j;
	int	*tmp;

	count = ft_lstsize(data->a);
	j = 0;
	while (j < count)
	{
		tmp = data->a->content;
		if (int_get_bit(*tmp, i) == 1)
			push_ops(data, &ra);
		else
			push_ops(data, &pb);
		j++;
	}
	while (data->b != NULL)
		push_ops(data, &pa);
}

int	is_sorted(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*
** Main function for bitshift sort. It performs the sort for every bit
** up to the number of bits required to represent the maximum value.
*/
void	bitshift(t_data *data)
{
	int	i;
	int	max_bits;

	if (data->a == NULL)
		return ;
	if (is_sorted(data->a))
		return ;
	max_bits = get_max_bits(data->a);
	i = 0;
	while (i < max_bits)
	{
		bitshift_step(data, i);
		if (is_sorted(data->a))
			break ;
		i++;
	}
}
