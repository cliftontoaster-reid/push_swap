/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:31:35 by lfiorell          #+#    #+#             */
/*   Updated: 2025/03/03 15:47:15 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <limits.h>

long	ft_atol(const char *nptr)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (ft_ciswhite(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
		if ((result * sign) > LONG_MAX || (result * sign) < LONG_MIN)
			break ;
	}
	if ((result * sign) > LONG_MAX)
		return (LONG_MAX);
	if ((result * sign) < LONG_MIN)
		return (LONG_MIN);
	return (result * sign);
}
