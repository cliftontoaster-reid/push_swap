/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:24:58 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/25 11:21:20 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

t_op	*clone_op(t_op op)
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	if (!new)
		return (NULL);
	*new = op;
	return (new);
}
