/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:18:41 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/27 11:31:52 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "libft.h"
#include "str.h"

/// @brief Free all the data of the stacks.
/// @param data The data to free.
int	ft_kill_all_humans(t_human *data)
{
	if (!data)
		return (0);
	if (data->a)
		ft_lstclear(&data->a, free);
	if (data->b)
		ft_lstclear(&data->b, free);
	if (data->op)
		ft_lstclear(&data->op, free);
	free(data);
	return (0);
}

static int	parse_number_list(const char *arg, t_list **list)
{
	char	**str_nbr;
	int		i;
	int		*nbr;

	i = 0;
	str_nbr = ft_split(arg, ' ');
	if (!str_nbr)
		return (0);
	while (str_nbr[i])
	{
		nbr = ft_calloc(sizeof(int), 1);
		if (!nbr)
			return (0);
		*nbr = ft_atoi(str_nbr[i]);
		ft_lstadd_back(list, ft_lstnew(nbr));
		free(str_nbr[i]);
		i++;
	}
	free(str_nbr);
	return (1);
}

int	parse_list_args(int argc, char const *argv[], t_list **list)
{
	int	i;
	int	*nbr;

	i = 1;
	if (argc < 2)
		return (0);
	if (ft_strchr(argv[1], ' ') != NULL)
		return (parse_number_list(argv[1], list));
	while (i < argc)
	{
		nbr = malloc(sizeof(int));
		if (!nbr)
			return (0);
		*nbr = ft_atoi(argv[i]);
		ft_lstadd_back(list, ft_lstnew(nbr));
		i++;
	}
	return (1);
}

int	parse_list_envp(char *const envp[], t_list **list)
{
	char	*arg;

	arg = lst_startswith(envp, "ARG=");
	if (!arg)
		return (-1);
	arg += 4;
	if (!*arg)
		return (0);
	if (!parse_number_list(arg, list))
		return (0);
	return (1);
}

t_human	*ft_init_data(int argc, char const *argv[], char *const envp[])
{
	t_human	*data;
	int		i;

	data = ft_calloc(sizeof(t_human), 1);
	if (!data)
		return (NULL);
	i = parse_list_envp(envp, &data->a);
	if (i == 0)
	{
		ft_kill_all_humans(data);
		return (NULL);
	}
	if (i < 0)
		i = parse_list_args(argc, argv, &data->a);
	if (i == 0)
	{
		ft_kill_all_humans(data);
		return (NULL);
	}
	return (data);
}
