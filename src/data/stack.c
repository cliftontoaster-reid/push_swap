/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:49:53 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/04 14:31:03 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "job.h"

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

int	choose_input(int argc, char *argv[], char *const envp[], int **stack)
{
	int	res;

	if (argc == 0)
	{
		res = kill_meeeeeeeeeeeeeeeee(envp, stack);
		return (res);
	}
	else
	{
		*stack = ft_calloc(argc, sizeof(int));
		if (*stack == NULL)
			return (ERR_MALLOC);
		parse(argc, argv, *stack);
		return (ERR_MALLOC);
		parse(argc, argv, *stack);
		return (argc);
	}
}

int	parse_list(int argc, char *argv[], char *const envp[], t_data *data)
{
	int	*stack;
	int	*tmp;
	int	i;
	int	len;

	len = choose_input(argc, argv, envp, &stack);
	if (len < 0)
		return (len);
	quicksort(stack, 0, len - 1);
	data->index = stack;
	data->size = len;
	i = 0;
	while (i < len)
	{
		tmp = malloc(sizeof(int));
		*tmp = i;
		ft_lstadd_back(&data->a, ft_lstnew(tmp));
		i++;
	}
	return (0);
}
