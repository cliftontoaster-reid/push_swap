/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_findlst.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:00:06 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/28 11:36:29 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUnit/Basic.h"

extern "C"
{
#include "libft.h"
#include "str.h"
}

void test_lst_startswith(void)
{
  const char *list[] = {"ARG=1", "ARG=2", "ARG=3", NULL};
  const char *str = "ARG=";
  char *res;

  res = lst_startswith((char *const *)list, str);

  CU_ASSERT_STRING_EQUAL(res, "ARG=1");

  str = "ARG=2";
  res = lst_startswith((char *const *)list, str);

  CU_ASSERT_STRING_EQUAL(res, "ARG=2");
}

void test_lst_startswith_failure(void)
{
  const char *list[] = {"ARG=1", "ARG=2", "ARG=3", NULL};
  const char *str = "ARG=4";
  char *res;

  res = lst_startswith((char *const *)list, str);

  CU_ASSERT_PTR_NULL(res);

  str = "OwO";

  res = lst_startswith((char *const *)list, str);

  CU_ASSERT_PTR_NULL(res);
}
