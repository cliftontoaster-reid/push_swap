/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:49:53 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/03 12:46:43 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

int	parse(int argc, char *argv[], int *stack)
{
	int	i;
	int	j;

	i = 0;
	if (!stack)
		return (ERR_MALLOC);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (ERR_ARG_TYPE);
			j++;
		}
		stack[i] = ft_atoi(argv[i]);
		for (int k = 0; k < i; k++)
		{
			if (stack[k] == stack[i])
				return (ERR_DUPL);
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
