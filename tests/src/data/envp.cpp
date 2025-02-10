/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:54:38 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/03 17:12:14 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUnit/Basic.h"

extern "C"
{
#include "data.h"
}

void test_envp_contains()
{
  char *envp[] = {(char *)"KEY=VALUE", nullptr};
  CU_ASSERT_EQUAL(envp_contains(envp, (char *)"KEY"), 1);
  CU_ASSERT_EQUAL(envp_contains(envp, (char *)"VALUE"), 0);
}

void test_envp_get()
{
  char *envp[] = {(char *)"KEY=VALUE", nullptr};
  CU_ASSERT_STRING_EQUAL(envp_get(envp, (char *)"KEY"), "VALUE");
  CU_ASSERT_EQUAL(envp_get(envp, (char *)"VALUE"), nullptr);
}