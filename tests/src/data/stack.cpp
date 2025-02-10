/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:38:28 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/10 22:00:55 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CU_ASSERT_LIST_CONTENT_EQ(list, expected)           \
  do                                                        \
  {                                                         \
    CU_ASSERT_PTR_NOT_NULL_FATAL((list));                   \
    CU_ASSERT_EQUAL(*(int *)((list)->content), (expected)); \
  } while (0)

extern "C"
{
#include "data.h"
}

#include "CUnit/Basic.h"

void test_parse_null_stack()
{
  char *argv[] = {(char *)"123", nullptr};
  int *stack = nullptr;
  int result = choose_input(1, (const char **)argv, nullptr, &stack);
  CU_ASSERT_NOT_EQUAL(result, ERR_MALLOC);
  free(stack);
}

void test_parse_invalid_arg()
{
  char *argv[] = {(char *)"12x", nullptr};
  int *stack = nullptr;
  int result = choose_input(1, (const char **)argv, nullptr, &stack);
  CU_ASSERT_EQUAL(result, ERR_ARG_TYPE);
  free(stack);
}

void test_parse_valid_args()
{
  char *argv[] = {(char *)"123", (char *)"456", nullptr};
  int *stack = nullptr;
  choose_input(2, (const char **)argv, nullptr, &stack);
  CU_ASSERT_PTR_NOT_NULL_FATAL(stack);
  CU_ASSERT_EQUAL(stack[0], 123);
  CU_ASSERT_EQUAL(stack[1], 456);
  free(stack);
}

void test_parse_dupl_args()
{
  char *argv[] = {(char *)"123", (char *)"123", nullptr};
  int *stack = nullptr;
  int result = choose_input(2, (const char **)argv, nullptr, &stack);
  CU_ASSERT_EQUAL(result, ERR_DUPL);
  free(stack);
}

void test_parse_envp()
{
  int *stack = nullptr;
  char *envp[] = {(char *)"ARG=1 2 3"};
  char *argv[] = {nullptr};
  int argc = 0;
  choose_input(argc, (const char **)argv, (const char **)envp, &stack);

  CU_ASSERT_PTR_NOT_NULL_FATAL(stack);
  CU_ASSERT_EQUAL(stack[0], 1);
  CU_ASSERT_EQUAL(stack[1], 2);
  CU_ASSERT_EQUAL(stack[2], 3);

  free(stack);
}

void test_parse_list_args()
{
  char *argv[] = {(char *)"1", (char *)"-5", (char *)"3", nullptr};
  int argc = 3;

  t_data *data;

  data = (t_data *)malloc(sizeof(t_data));
  ft_bzero(data, sizeof(t_data));

  int res = parse_list(argc, (const char **)argv, nullptr, data);
  if (res != 0)
  {
    kill_thatguy(data);
    CU_FAIL("parse_list failed");
  }

  CU_ASSERT_LIST_CONTENT_EQ(data->a, 1);
  CU_ASSERT_LIST_CONTENT_EQ(data->a->next, 0);
  CU_ASSERT_LIST_CONTENT_EQ(data->a->next->next, 2);

  CU_ASSERT_PTR_NULL(data->b);

  CU_ASSERT_EQUAL(data->size, 3);

  CU_ASSERT_EQUAL(data->index[0], -5);
  CU_ASSERT_EQUAL(data->index[1], 1);
  CU_ASSERT_EQUAL(data->index[2], 3);

  kill_thatguy(data);
}
