/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:49:53 by lfiorell          #+#    #+#             */
/*   Updated: 2025/03/03 15:38:51 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "job.h"

int			parse(int argc, char *argv[], int *stack);

static int	same_arg(const char *argv[], int **stack)
{
	int		res;
	char	*eee;

	*stack = NULL;
	eee = ft_strjoin("ARG=", argv[0]);
	res = kill_meeeeeeeeeeeeeeeee((const char **)&eee, stack);
	free(eee);
	return (res);
}

int	choose_input(int argc, const char *argv[], char const *envp[], int **stack)
{
	int	res;

	if (argc == 0)
	{
		*stack = NULL;
		res = kill_meeeeeeeeeeeeeeeee(envp, stack);
		return (res);
	}
	else
	{
		if (ft_strchr(argv[0], ' '))
			return (same_arg(argv, stack));
		if (argc == 0)
			return (ERR_ARG);
		*stack = ft_calloc(argc, sizeof(int));
		if (*stack == NULL)
			return (ERR_MALLOC);
		res = parse(argc, (char **)argv, *stack);
		if (res < 0)
			return (res);
		return (argc);
	}
}

int	parse_list(int argc, const char *argv[], char const *envp[], t_data *data)
{
	int	*stack;
	int	*tmp;
	int	i;
	int	len;

	len = choose_input(argc, argv, envp, &stack);
	if (len < 0)
	{
		free(stack);
		return (len);
	}
	data->index = clone_iarr(stack, len);
	quicksort(data->index, 0, len - 1);
	data->size = len;
	i = 0;
	while (i < len)
	{
		tmp = malloc(sizeof(int));
		*tmp = idx_of(data->index, len, stack[i]);
		ft_lstadd_back(&data->a, ft_lstnew(tmp));
		i++;
	}
	free(stack);
	return (0);
}
