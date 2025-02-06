/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:04:41 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/05 16:08:43 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOB_H
# define JOB_H

# include "data.h"

void	quicksort(int *arr, int low, int high);
void	bitshift(t_data *data);
void	push_ops(t_data *data, void (*op)(t_list **, t_list **));
char	*func_to_char(void (*op)(t_list **, t_list **));
void	print_ops(t_data *owo);
int		int_get_bit(int n, int i);
int		get_max_bits(t_list *stack);
void	bitshift_step(t_data *data, int i);

void	sort_two(t_data *data);
void	sort_three(t_data *data);
void	sort_four(t_data *data);
void	sort_five(t_data *data);

#endif
