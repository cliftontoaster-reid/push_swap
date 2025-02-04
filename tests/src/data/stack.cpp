/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:38:28 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/04 13:06:55 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C"
{
#include "data.h"
  int parse(int argc, char *argv[], int *stack);
}

#include <CUnit/CUnit.h>
#include "CUnit/Basic.h"

void test_parse_null_stack()
{
  char *argv[] = {(char *)"123", nullptr};
  int result = parse(1, argv, nullptr);
  CU_ASSERT_EQUAL(result, ERR_MALLOC);
}

void test_parse_invalid_arg()
{
  char *argv[] = {(char *)"12x", nullptr};
  int mockStack[1];
  int result = parse(1, argv, mockStack);
  CU_ASSERT_EQUAL(result, ERR_ARG_TYPE);
}

void test_parse_valid_args()
{
  char *argv[] = {(char *)"123", (char *)"456", nullptr};
  int mockStack[2];
  int result = parse(2, argv, mockStack);
  CU_ASSERT_EQUAL(result, 0);
  CU_ASSERT_EQUAL(mockStack[0], 123);
  CU_ASSERT_EQUAL(mockStack[1], 456);
}

void test_parse_dupl_args()
{
  char *argv[] = {(char *)"123", (char *)"123", nullptr};
  int mockStack[2];
  int result = parse(2, argv, mockStack);
  CU_ASSERT_EQUAL(result, ERR_DUPL);
}

void test_parse_envp()
{
  int *stack = nullptr;
  char *envp[] = {(char *)"ARG=1 2 3"};
  char *argv[] = {nullptr};
  int argc = 0;
  choose_input(argc, argv, envp, &stack);

  CU_ASSERT_PTR_NOT_NULL_FATAL(stack);
  CU_ASSERT_EQUAL(stack[0], 1);
  CU_ASSERT_EQUAL(stack[1], 2);
  CU_ASSERT_EQUAL(stack[2], 3);

  free(stack);
}