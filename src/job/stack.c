/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:53:09 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/05 14:50:40 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "job.h"

void	push_ops(t_data *data, void (*op)(t_list **, t_list **))
{
	t_list	*new;

	if (op == NULL)
		return ;
	op(&data->a, &data->b);
	new = ft_lstnew((void *)op);
	if (new == NULL)
		return ;
	ft_lstadd_back(&data->ops, new);
}

char	*func_to_char(void (*op)(t_list **, t_list **))
{
	if (op == &pa)
		return ("pa");
	else if (op == &pb)
		return ("pb");
	else if (op == &sa)
		return ("sa");
	else if (op == &sb)
		return ("sb");
	else if (op == &ss)
		return ("ss");
	else if (op == &ra)
		return ("ra");
	else if (op == &rb)
		return ("rb");
	else if (op == &rr)
		return ("rr");
	else if (op == &rra)
		return ("rra");
	else if (op == &rrb)
		return ("rrb");
	else if (op == &rrr)
		return ("rrr");
	return ("unknown");
}

void	print_ops(t_data *owo)
{
	t_list	*ops;
	char	*op;

	ops = owo->ops;
	while (ops)
	{
		op = func_to_char((void (*)(t_list **, t_list **))ops->content);
		ft_putendl_fd(op, 1);
		ops = ops->next;
	}
}
