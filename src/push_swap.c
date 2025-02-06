/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:26:02 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/06 12:16:19 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "job.h"

int	e(t_data *r)
{
	kill_thatguy(r);
	ft_putstr_fd("Error\n", 2);
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
		return (e(guy));
	if (guy->size > 4)
		bitshift(guy);
	else if (guy->size == 4)
		sort_four(guy);
	else if (guy->size == 3)
		sort_three(guy);
	else if (guy->size == 2)
		sort_two(guy);
	print_ops(guy);
	kill_thatguy(guy);
	return (0);
}
