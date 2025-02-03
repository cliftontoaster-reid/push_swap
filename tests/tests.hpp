/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:05:46 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/03 17:17:44 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// data/stack.cpp
void test_parse_invalid_arg();
void test_parse_valid_args();
void test_parse_null_stack();
void test_parse_dupl_args();

// cmd/arc_rotate.cpp
void test_rra(void);
void test_rrb(void);

// cmd/push.cpp
void test_pa(void);
void test_pb(void);

// cmd/rotate.cpp
void test_ra(void);
void test_rb(void);

// cmd/swap.cpp
void test_sa();
void test_sb();

// data/envp.cpp
void test_envp_contains();
void test_envp_get();

// job/quicksort.cpp
void test_quicksort(void);