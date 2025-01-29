/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:39:24 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/28 15:38:17 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H EEEEEEEEEEEEEEEEEE

# include "data.h"
# include "libft.h"
# include "nbr.h"
# include "operations.h"

typedef struct s_stack_op
{
	t_op	normal;
	t_op	revers;
}			t_stack_op;

void		exec_offset(t_human *data, int stack, int offset);
void		exec_op(t_human *data, t_op op);
int			push_op(t_human *data, t_op op);
void		print_stacks(t_human *data);
t_list		*clone_list(t_list *e);

#endif
