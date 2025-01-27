/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:43:07 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/25 11:41:40 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "libft.h"

/// @brief A structure to hold the data of the stacks.
typedef struct s_human
{
	/// @brief The stack A.
	t_list	*a;
	/// @brief The stack B.
	t_list	*b;
	/// @brief The operations performed on the stacks.
	t_list	*op;
	/// @brief The minimum value of the stack.
	int		min;
	/// @brief The maximum value of the stack.
	int		max;
}			t_human;

int			ft_kill_all_humans(t_human *data);
t_human		*ft_init_data(int argc, char const *argv[], char *const envp[]);

int			parse_list_args(int argc, char const *argv[], t_list **list);
int			parse_list_envp(char *const envp[], t_list **list);

#endif
