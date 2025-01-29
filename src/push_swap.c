/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:55:10 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/29 20:40:52 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "nbr.h"
#include "pretzel.h"
#include "utils.h"

static int	copilot_no(t_human *data)
{
	ft_kill_all_humans(data);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

static int	copilot_yes(t_human *data)
{
	ft_kill_all_humans(data);
	return (0);
}

static char	*op_to_str(t_op op)
{
	if (op == SA)
		return ("sa");
	if (op == SB)
		return ("sb");
	if (op == SS)
		return ("ss");
	if (op == PA)
		return ("pa");
	if (op == PB)
		return ("pb");
	if (op == RA)
		return ("ra");
	if (op == RB)
		return ("rb");
	if (op == RR)
		return ("rr");
	if (op == RRA)
		return ("rra");
	if (op == RRB)
		return ("rrb");
	if (op == RRR)
		return ("rrr");
	return (NULL);
}

static void	print_op(t_human *data)
{
	t_list	*tmp;

	while (data->op)
	{
		ft_putstr_fd(op_to_str(*(t_op *)data->op->content), 1);
		ft_putchar_fd('\n', 1);
		tmp = data->op;
		data->op = data->op->next;
		free(tmp->content);
		free(tmp);
	}
}

int	main(int argc, char const *argv[], char *const envp[])
{
	t_human	*data;

	data = ft_init_data(argc, argv, envp);
	if (!data)
		return (copilot_no(data));
	if (ft_lstsize(data->a) <= 1)
		return (copilot_yes(data));
	if (ilst_sorted(data->a))
		return (copilot_yes(data));
	pretzel(data);
	print_op(data);
	return (copilot_yes(data));
}
