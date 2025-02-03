/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:24:42 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/03 12:42:19 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

int	ft_split_count(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	ft_split_free(char **split)
{
	int	i;
	int	len;

	if (!split)
		return (0);
	i = 0;
	len = ft_split_count(split);
	while (split[i])
	{
		ft_bzero(split[i], ft_strlen(split[i]));
		free(split[i]);
		i++;
	}
	ft_bzero(split, len * sizeof(char *));
	free(split);
	return (0);
}
