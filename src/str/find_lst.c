/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:51:19 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/21 19:00:06 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

/// @brief Find the first string in the list that starts with the string \p str.
/// @param list The list of strings.
/// @param str The string to search for.
/// @return The first string that starts with \p str or `NULL` if no string
char	*lst_startswith(char *const list[], const char *str)
{
	int	i;
	int	j;

	i = 0;
	while (list[i])
	{
		j = 0;
		while (list[i][j] == str[j] && list[i][j] && str[j])
			j++;
		if (!str[j])
			return (list[i]);
		i++;
	}
	return (NULL);
}
