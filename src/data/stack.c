/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:49:53 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/03 17:33:43 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static int	validate_argument(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (!ft_isdigit(str[j]))
			return (0);
		j++;
	}
	return (1);
}

int	parse(int argc, char *argv[], int *stack)
{
	int	i;
	int	k;

	i = 0;
	if (!stack)
		return (ERR_MALLOC);
	while (i < argc)
	{
		if (!validate_argument(argv[i]))
			return (ERR_ARG_TYPE);
		stack[i] = ft_atoi(argv[i]);
		k = 0;
		while (k < i)
		{
			if (stack[k] == stack[i])
				return (ERR_DUPL);
			k++;
		}
		i++;
	}
	return (0);
}

int	parse_list(int argc, char *argv[], char *const envp[], t_data *data)
{
	int		*stack;
	int		i;
	char	*arg;
	char	**split;

	stack = ft_calloc(argc, sizeof(int));
	if (stack == NULL)
		return (ERR_MALLOC);
	parse(argc, argv, stack);
	if (envp_contains(envp, "ARG"))
	{
		arg = envp_get(envp, "ARG");
		split = ft_split(arg, ' ');
		i = parse(ft_split_count(split), split, stack);
		if (i < 0)
		{
			ft_split_free(split);
			free(stack);
			return (i);
		}
	}
	(void)data;
	return (0);
}
