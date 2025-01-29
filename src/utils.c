/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:34:46 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/28 15:28:39 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	exec_offset(t_human *data, int stack, int offset)
{
	t_stack_op	uwu;

	if (stack == 0)
	{
		uwu.normal = RA;
		uwu.revers = RRA;
	}
	else
	{
		uwu.normal = RB;
		uwu.revers = RRB;
	}
	if (offset > 0)
	{
		while (offset--)
			push_op(data, uwu.normal);
	}
	else
	{
		while (offset++)
			push_op(data, uwu.revers);
	}
}

void	print_stacks(t_human *data)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = data->a;
	tmp_b = data->b;
	ft_printf("Stack A: ");
	while (tmp_a)
	{
		ft_printf("%d ", *(int *)tmp_a->content);
		tmp_a = tmp_a->next;
	}
	ft_printf("\nStack B: ");
	while (tmp_b)
	{
		ft_printf("%d ", *(int *)tmp_b->content);
		tmp_b = tmp_b->next;
	}
	ft_printf("\n\n");
}

void	exec_op(t_human *data, t_op op)
{
	if (op == SA)
		sa(&data->a);
	else if (op == SB)
		sb(&data->b);
	else if (op == SS)
		ss(&data->a, &data->b);
	else if (op == PA)
		pa(&data->a, &data->b);
	else if (op == PB)
		pb(&data->a, &data->b);
	else if (op == RA)
		ra(&data->a);
	else if (op == RB)
		rb(&data->b);
	else if (op == RR)
		rr(&data->a, &data->b);
	else if (op == RRA)
		rra(&data->a);
	else if (op == RRB)
		rrb(&data->b);
	else if (op == RRR)
		rrr(&data->a, &data->b);
}

int	push_op(t_human *data, t_op op)
{
	t_op	*new_op;
	t_list	*new_elem;

	new_op = clone_op(op);
	if (!new_op)
		return (1);
	exec_op(data, op);
	new_elem = ft_lstnew(new_op);
	if (!new_elem)
	{
		free(new_op);
		return (1);
	}
	ft_lstadd_back(&data->op, new_elem);
	return (0);
}

t_list	*clone_list(t_list *e)
{
	t_list	*new;
	t_list	*current;
	t_list	*node;

	if (!e)
		return (NULL);
	new = ft_lstnew(e->content);
	if (!new)
		return (NULL);
	current = new;
	e = e->next;
	while (e)
	{
		node = ft_lstnew(e->content);
		if (!node)
		{
			ft_lstclear(&new, free);
			return (NULL);
		}
		current->next = node;
		current = node;
		e = e->next;
	}
	return (new);
}
