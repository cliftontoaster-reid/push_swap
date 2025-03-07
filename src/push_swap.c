/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:26:02 by lfiorell          #+#    #+#             */
/*   Updated: 2025/03/07 15:03:37 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "job.h"

int					is_sorted(t_list *stack);

int	e(t_data *r)
{
	kill_thatguy(r);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	ee(t_data *r, int err)
{
	if (err != ERR_ARG)
		e(r);
	else
		kill_thatguy(r);
	return (1);
}

static inline void	decide_algo(t_data *guy)
{
	if (guy->size > 5)
		bitshift(guy);
	else if (guy->size == 5)
		sort_five(guy);
	else if (guy->size == 4)
		sort_four(guy);
	else if (guy->size == 3)
		sort_three(guy);
	else if (guy->size == 2)
		sort_two(guy);
}

int	main(int argc, char const *argv[], char const *envp[])
{
	t_data	*guy;
	int		res;

	guy = init_thatguy();
	if (!guy)
		return (e(guy));
	res = parse_list(argc - 1, argv + 1, envp, guy);
	if (res < 0)
		return (ee(guy, res));
	if (is_sorted(guy->a))
	{
		kill_thatguy(guy);
		return (0);
	}
	decide_algo(guy);
	print_ops(guy);
	kill_thatguy(guy);
	return (0);
}
