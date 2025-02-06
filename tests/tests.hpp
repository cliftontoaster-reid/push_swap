/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:05:46 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/06 11:57:40 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// data/stack.cpp
void test_parse_invalid_arg();
void test_parse_valid_args();
void test_parse_null_stack();
void test_parse_dupl_args();
void test_parse_envp();
void test_parse_list_args();

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

// job/stack.cpp
void test_push_ops(void);
void test_push_ops_null(void);
void test_push_ops_multiple(void);
void test_func_to_char();

// job/bitshift.cpp
void test_int_get_bit(void);
void test_get_max_bits(void);
void test_bitshift(void);
void test_bitshift_random(void);

// job/smol.cpp
void test_sort_two(void);
void test_sort_three(void);
void test_sort_four(void);
