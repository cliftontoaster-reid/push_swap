/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapush.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:00:15 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/22 17:31:03 by lfiorell         ###   ########.fr       */
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
  CU_add_test(suite, "List Start With", test_lst_startswith);
  CU_add_test(suite, "List Start With (Fail)", test_lst_startswith_failure);
  //
  CU_add_test(suite, "Push A", test_pa);
  CU_add_test(suite, "Push B", test_pb);
  CU_add_test(suite, "Rotate A", test_ra);
  CU_add_test(suite, "Rotate B", test_rb);
  CU_add_test(suite, "Rizz Rotate A", test_rra);
  CU_add_test(suite, "Rizz Rotate B", test_rrb);
  CU_add_test(suite, "Swap A", test_sa);
  CU_add_test(suite, "Swap B", test_sb);
  //
  CU_add_test(suite, "Parse List Args", test_parse_list_args);
  CU_add_test(suite, "Parse List Envp", test_parse_list_envp);
  CU_add_test(suite, "Init Data Envp", test_init_data_envp);
  //
  CU_basic_run_tests();
  CU_cleanup_registry();
  return 0;
}
