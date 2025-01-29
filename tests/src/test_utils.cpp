/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:29:45 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/28 13:06:11 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUnit/Basic.h"

extern "C"
{
#include "libft.h"
#include "utils.h"
#include "operations.h"
}

static int ilst_cmp(t_list *a, t_list *b)
{
  if (!a && !b)
    return (0);
  if (!a || !b)
    return (1);
  if (*(int *)a->content != *(int *)b->content)
    return (1);
  return (ilst_cmp(a->next, b->next));
}

void test_push_op(void)
{
  t_human *expected = (t_human *)calloc(1, sizeof(t_human));
  t_human *data = (t_human *)calloc(1, sizeof(t_human));

  ft_lstadd_back(&expected->a, ft_lstnew(ft_calloc(sizeof(int), 1)));
  ft_lstadd_back(&expected->b, ft_lstnew(ft_calloc(sizeof(int), 2)));
  ft_lstadd_back(&expected->a, ft_lstnew(ft_calloc(sizeof(int), 3)));
  ft_lstadd_back(&expected->b, ft_lstnew(ft_calloc(sizeof(int), 4)));

  ft_lstadd_back(&data->a, ft_lstnew(ft_calloc(sizeof(int), 1)));
  ft_lstadd_back(&data->b, ft_lstnew(ft_calloc(sizeof(int), 2)));
  ft_lstadd_back(&data->a, ft_lstnew(ft_calloc(sizeof(int), 3)));
  ft_lstadd_back(&data->b, ft_lstnew(ft_calloc(sizeof(int), 4)));

  // SA - Swap A
  sa(&expected->a);
  push_op(data, SA);

  CU_ASSERT(ilst_cmp(expected->a, data->a) == 0);
  // SB - Swap B
  sb(&expected->b);
  push_op(data, SB);

  CU_ASSERT(ilst_cmp(expected->b, data->b) == 0);
  // SS - Swap A and B
  ss(&expected->a, &expected->b);
  push_op(data, SS);

  CU_ASSERT(ilst_cmp(expected->a, data->a) == 0);
  CU_ASSERT(ilst_cmp(expected->b, data->b) == 0);
  // PA - Push A
  pa(&expected->a, &expected->b);
  push_op(data, PA);

  CU_ASSERT(ilst_cmp(expected->a, data->a) == 0);
  CU_ASSERT(ilst_cmp(expected->b, data->b) == 0);
  // PB - Push B
  pb(&expected->a, &expected->b);
  push_op(data, PB);

  CU_ASSERT(ilst_cmp(expected->a, data->a) == 0);
  CU_ASSERT(ilst_cmp(expected->b, data->b) == 0);
  // RA - Rotate A
  ra(&expected->a);
  push_op(data, RA);

  CU_ASSERT(ilst_cmp(expected->a, data->a) == 0);
  // RB - Rotate B
  rb(&expected->b);
  push_op(data, RB);

  CU_ASSERT(ilst_cmp(expected->b, data->b) == 0);
  // RR - Rotate A and B
  rr(&expected->a, &expected->b);
  push_op(data, RR);

  CU_ASSERT(ilst_cmp(expected->a, data->a) == 0);
  CU_ASSERT(ilst_cmp(expected->b, data->b) == 0);
  // RRA - Reverse Rotate A
  rra(&expected->a);
  push_op(data, RRA);

  CU_ASSERT(ilst_cmp(expected->a, data->a) == 0);
  // RRB - Reverse Rotate B
  rrb(&expected->b);
  push_op(data, RRB);

  CU_ASSERT(ilst_cmp(expected->b, data->b) == 0);
  // RRR - Reverse Rotate A and B
  rrr(&expected->a, &expected->b);
  push_op(data, RRR);

  CU_ASSERT(ilst_cmp(expected->a, data->a) == 0);
  CU_ASSERT(ilst_cmp(expected->b, data->b) == 0);
  // Free memory

  ft_kill_all_humans(expected);
  ft_kill_all_humans(data);

  // OWO what's this?
}

void test_exec_op(void)
{
  t_human *data = (t_human *)calloc(1, sizeof(t_human));
  t_op expected_ops[] = {SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};
  int num_ops = sizeof(expected_ops) / sizeof(t_op);

  // Perform each operation and add to data->op list
  for (int i = 0; i < num_ops; i++)
    push_op(data, expected_ops[i]);

  // Verify the operation list
  t_list *current = data->op;
  for (int i = 0; i < num_ops; i++)
  {
    CU_ASSERT_PTR_NOT_NULL_FATAL(current);
    CU_ASSERT_EQUAL(*(t_op *)current->content, expected_ops[i]);
    current = current->next;
  }
  CU_ASSERT_PTR_NULL(current);

  ft_kill_all_humans(data);
}

static void no(void *data)
{
  (void)data;
}

void test_clone_list(void)
{
  t_list *list = ft_lstnew(ft_calloc(sizeof(int), 1));
  ft_lstadd_back(&list, ft_lstnew(ft_calloc(sizeof(int), 2)));
  ft_lstadd_back(&list, ft_lstnew(ft_calloc(sizeof(int), 3)));

  t_list *clone = clone_list(list);

  // Check that the clone is not the same as the original list
  CU_ASSERT_PTR_NOT_EQUAL(clone, list);

  // Check that the contents of the clone match the original list
  CU_ASSERT(ilst_cmp(clone, list) == 0);

  // Ensure that each node in the clone is a distinct memory allocation
  t_list *orig = list;
  t_list *cl = clone;
  while (orig && cl)
  {
    CU_ASSERT_PTR_NOT_EQUAL(orig, cl);
    CU_ASSERT_PTR_EQUAL(orig->content, cl->content);
    orig = orig->next;
    cl = cl->next;
  }

  // Free memory
  ft_lstclear(&list, free);
  ft_lstclear(&clone, no);
}