/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:21:12 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/04 13:38:14 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

int	envp_contains(char *const envp[], char *key)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], key, ft_strlen(key)) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*envp_get(char *const envp[], char *key)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], key, ft_strlen(key)) == 0)
			return (envp[i] + ft_strlen(key) + 1);
		i++;
	}
	return (NULL);
}

int	kill_meeeeeeeeeeeeeeeee(char *const envp[], int **stack)
{
	int		i;
	char	*arg;
	char	**split;
	int		argc;

	if (envp_contains(envp, "ARG"))
	{
		arg = envp_get(envp, "ARG");
		split = ft_split(arg, ' ');
		argc = ft_split_count(split);
		*stack = ft_calloc(argc, sizeof(int));
		if (*stack == NULL)
			return (ERR_MALLOC);
		i = parse(argc, split, *stack);
		ft_split_free(split);
		if (i < 0)
			return (i);
	}
	return (0);
}
