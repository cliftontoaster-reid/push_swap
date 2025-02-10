/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:57:42 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/05 14:11:44 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUnit/Basic.h"

extern "C"
{
#include "job.h"
#include "cmd.h"
}

void test_push_ops()
{
  t_data *data = init_thatguy();

  push_ops(data, &sa);

  CU_ASSERT_PTR_NOT_NULL_FATAL(data->ops);
  CU_ASSERT_PTR_EQUAL(data->ops->content, &sa);

  kill_thatguy(data);
}

void test_push_ops_null()
{
  t_data *data = init_thatguy();

  CU_ASSERT_PTR_NULL(data->ops);

  push_ops(data, NULL);

  CU_ASSERT_PTR_NULL(data->ops);

  kill_thatguy(data);
}

void test_push_ops_multiple()
{
  t_data *data = init_thatguy();

  push_ops(data, &sa);
  push_ops(data, &ra);
  push_ops(data, &pb);

  CU_ASSERT_PTR_NOT_NULL_FATAL(data->ops);
  CU_ASSERT_PTR_EQUAL(data->ops->content, &sa);
  CU_ASSERT_PTR_NOT_NULL_FATAL(data->ops->next);
  CU_ASSERT_PTR_EQUAL(data->ops->next->content, &ra);
  CU_ASSERT_PTR_NOT_NULL_FATAL(data->ops->next->next);
  CU_ASSERT_PTR_EQUAL(data->ops->next->next->content, &pb);

  kill_thatguy(data);
}

void test_func_to_char()
{
  CU_ASSERT_STRING_EQUAL(func_to_char(&pa), "pa");
  CU_ASSERT_STRING_EQUAL(func_to_char(&pb), "pb");
  CU_ASSERT_STRING_EQUAL(func_to_char(&sa), "sa");
  CU_ASSERT_STRING_EQUAL(func_to_char(&sb), "sb");
  CU_ASSERT_STRING_EQUAL(func_to_char(&ss), "ss");
  CU_ASSERT_STRING_EQUAL(func_to_char(&ra), "ra");
  CU_ASSERT_STRING_EQUAL(func_to_char(&rb), "rb");
  CU_ASSERT_STRING_EQUAL(func_to_char(&rr), "rr");
  CU_ASSERT_STRING_EQUAL(func_to_char(&rra), "rra");
  CU_ASSERT_STRING_EQUAL(func_to_char(&rrb), "rrb");
  CU_ASSERT_STRING_EQUAL(func_to_char(&rrr), "rrr");
  CU_ASSERT_STRING_EQUAL(func_to_char(NULL), "unknown");
  CU_ASSERT_STRING_EQUAL(func_to_char((void (*)(t_list **, t_list **))0x1), "unknown");
}
