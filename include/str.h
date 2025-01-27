/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:50:33 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/22 14:25:02 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include "libft.h"
# include <stddef.h>

// find.c

char	*untilchar_copy(const char *str, char c);
char	*untilchar_read(int fd, char c);

/// @brief Copy the string until the string \p tiny is encountered,
///        \p tiny not included.
/// @param str The string to search through.
/// @param tiny The string to search for.
/// @return The new string or `NULL` if the allocation or the \p tiny string
///         is not found.
char	*untilstr_copy(const char *str, const char *c);
char	*untilstr_read(int fd, const char *c);

// find_lst.c

/// @brief Find the first string in the list that starts with the string \p str.
/// @param list The list of strings.
/// @param str The string to search for.
/// @return The first string that starts with \p str or `NULL` if no string
char	*lst_startswith(char *const list[], const char *str);

#endif
