/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:24:23 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/06 12:12:57 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# define ERR_MALLOC -1
# define ERR_ARG_TYPE -2
# define ERR_DUPL -3
# define ERR_ARG -4
# define KILL free

# include "libft.h"

typedef struct s_data
{
	t_list	*a;
	t_list	*b;
	t_list	*ops;
	int		*index;
	int		size;
}			t_data;

t_data		*init_thatguy(void);
void		kill_thatguy(t_data *data);
int			parse_list(int argc, const char *argv[], char const *envp[],
				t_data *data);
int			envp_contains(char const *envp[], char *key);
const char	*envp_get(char const *envp[], char *key);
int			ft_split_count(char **split);
int			ft_split_free(char **split);
int			choose_input(int argc, const char *argv[], char const *envp[],
				int **stack);
int			kill_meeeeeeeeeeeeeeeee(char const *envp[], int **stack);
int			*clone_iarr(int *arr, int len);
int			idx_of(int *arr, int len, int val);

#endif
