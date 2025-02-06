/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:38:28 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/05 13:56:42 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

t_data	*init_thatguy(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	ft_bzero(data, sizeof(t_data));
	return (data);
}

void	zeroize(void *ptr)
{
	ft_bzero(ptr, sizeof(int));
	free(ptr);
}

void	nokill(void *ptr)
{
	(void)ptr;
}

void	kill_thatguy(t_data *data)
{
	if (data->a)
		ft_lstclear(&data->a, zeroize);
	if (data->b)
		ft_lstclear(&data->b, zeroize);
	if (data->ops)
		ft_lstclear(&data->ops, nokill);
	if (data->index)
		free(data->index);
	ft_bzero(data, sizeof(t_data));
	KILL(data);
}
