/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:38:28 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/11 16:25:26 by lfiorell         ###   ########.fr       */
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
  const char *argv[] = {nullptr};
  int *stack = nullptr;
  int result = choose_input(0, argv, nullptr, &stack);
  CU_ASSERT_EQUAL(result, ERR_MALLOC);
}

void test_parse_invalid_arg()
{
  const char *argv[] = {"123", "abc", nullptr};
  int *stack = nullptr;
  int result = choose_input(2, argv, nullptr, &stack);
  CU_ASSERT_EQUAL(result, ERR_ARG_TYPE);
  free(stack);
}

void test_parse_valid_args()
{
  const char *argv[] = {"123", "456", nullptr};
  int *stack = nullptr;
  int result = choose_input(2, argv, nullptr, &stack);
  CU_ASSERT_EQUAL(result, 2);
  CU_ASSERT_EQUAL(stack[0], 123);
  CU_ASSERT_EQUAL(stack[1], 456);
  free(stack);
}

void test_parse_dupl_args()
{
  const char *argv[] = {"123", "123", nullptr};
  int *stack = nullptr;
  int result = choose_input(2, argv, nullptr, &stack);
  CU_ASSERT_EQUAL(result, ERR_DUPL);
  CU_ASSERT_EQUAL(stack[0], 123);
  CU_ASSERT_EQUAL(stack[1], 123);
  free(stack);
}

void test_parse_envp()
{
  const char *envp[] = {"ARG=1 2 3", nullptr};
  int *stack = nullptr;
  int result = choose_input(0, nullptr, envp, &stack);
  CU_ASSERT_EQUAL(result, 3);
  CU_ASSERT_EQUAL(stack[0], 1);
  CU_ASSERT_EQUAL(stack[1], 2);
  CU_ASSERT_EQUAL(stack[2], 3);
  free(stack);
}

void test_parse_list_args()
{
  const char *argv[] = {"1", "-5", "3", nullptr};
  int argc = 3;

  t_data *data;

  data = (t_data *)malloc(sizeof(t_data));
  ft_bzero(data, sizeof(t_data));

  int res = parse_list(argc, argv, nullptr, data);
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
