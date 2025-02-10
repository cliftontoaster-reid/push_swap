/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:26:53 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/04 17:27:27 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

int	*clone_iarr(int *arr, int len)
{
	int	*clone;
	int	i;

	clone = ft_calloc(len, sizeof(int));
	if (!clone)
		return (NULL);
	i = 0;
	while (i < len)
	{
		clone[i] = arr[i];
		i++;
	}
	return (clone);
}

int	idx_of(int *arr, int len, int val)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == val)
			return (i);
		i++;
	}
	return (-1);
}
