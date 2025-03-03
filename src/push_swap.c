/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:26:02 by lfiorell          #+#    #+#             */
/*   Updated: 2025/03/03 15:27:47 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "job.h"

int	is_sorted(t_list *stack);

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
	if (guy->size > 3)
		bitshift(guy);
	else if (guy->size == 3)
		sort_three(guy);
	else if (guy->size == 2)
		sort_two(guy);
	print_ops(guy);
	kill_thatguy(guy);
	return (0);
}
