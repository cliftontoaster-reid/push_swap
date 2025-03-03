/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:35:31 by lfiorell          #+#    #+#             */
/*   Updated: 2025/03/03 15:42:16 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <limits.h>

static int	validate_argument(const char *str)
{
	int	j;

	j = 0;
	if (str[0] == '-')
		j++;
	if (str[j] == '\0')
		return (0);
	while (str[j])
	{
		if (!ft_isdigit(str[j]))
			return (0);
		j++;
	}
	return (1);
}

static int	parse_step(int i, const char *argv[], int *stack)
{
	int		k;
	long	tmp;

	if (!validate_argument(argv[i]))
		return (ERR_ARG_TYPE);
	tmp = ft_atol(argv[i]);
	if (tmp > INT_MAX || tmp < INT_MIN)
		return (ERR_ARG_TYPE);
	stack[i] = (int)tmp;
	k = 0;
	while (k < i)
	{
		if (stack[k] == stack[i])
			return (ERR_DUPL);
		k++;
	}
	i++;
	return (0);
}

int	parse(int argc, const char *argv[], int *stack)
{
	int	i;
	int	res;

	i = 0;
	if (!stack)
		return (ERR_MALLOC);
	while (i < argc)
	{
		res = parse_step(i, argv, stack);
		if (res < 0)
			return (res);
		i++;
	}
	return (0);
}
