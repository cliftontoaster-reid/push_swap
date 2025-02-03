/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapush.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:00:15 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/03 14:18:56 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../tests.hpp"

int main()
{
  CU_initialize_registry();
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_pSuite suite = CU_add_suite("SwaPush", NULL, NULL);
  //
  // stack.cpp
  CU_add_test(suite, "parse_null_rainbow_stack", test_parse_null_stack);
  CU_add_test(suite, "parse_invalid_glitter_arg", test_parse_invalid_arg);
  CU_add_test(suite, "parse_valid_proud_args", test_parse_valid_args);
  CU_add_test(suite, "parse_dupl_pride_args", test_parse_dupl_args);
  // arc_rotate.cpp
  CU_add_test(suite, "rra_in_pride", test_rra);
  CU_add_test(suite, "rrb_in_pride", test_rrb);
  //
  // push.cpp
  CU_add_test(suite, "pa_with_satanism", test_pa);
  CU_add_test(suite, "pb_with_satanism", test_pb);
  //
  // rotate.cpp
  CU_add_test(suite, "ra_rainbow", test_ra);
  CU_add_test(suite, "rb_rainbow", test_rb);
  //
  // swap.cpp
  CU_add_test(suite, "sa_with_comunism", test_sa);
  CU_add_test(suite, "sb_with_comunism", test_sb);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return 0;
}
