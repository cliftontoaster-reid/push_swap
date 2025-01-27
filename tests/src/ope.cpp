/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:26:03 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/22 15:45:08 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CUnit/CUnit.h>

extern "C"
{
#include "operations.h"
#include "libft.h"
}

static int *to_ptr(int n)
{
  int *ptr = (int *)calloc(sizeof(int), 1);
  *ptr = n;
  return ptr;
}

static t_list *to_lst(int n)
{
  return ft_lstnew(to_ptr(n));
}

void test_pa(void)
{
  t_list *a = ft_lstnew(to_ptr(1));
  ft_lstadd_back(&a, to_lst(2));

  t_list *b = ft_lstnew(to_ptr(3));
  ft_lstadd_back(&b, to_lst(4));

  pa(&a, &b);

  CU_ASSERT_EQUAL(*(int *)a->content, 3);
  CU_ASSERT_EQUAL(*(int *)a->next->content, 1);

  CU_ASSERT_EQUAL(*(int *)b->content, 4);

  ft_lstclear(&a, free);
  ft_lstclear(&b, free);
}

void test_pb(void)
{
  t_list *a = ft_lstnew(to_ptr(1));
  ft_lstadd_back(&a, to_lst(2));

  t_list *b = ft_lstnew(to_ptr(3));
  ft_lstadd_back(&b, to_lst(4));

  pb(&a, &b);

  CU_ASSERT_EQUAL(*(int *)b->content, 1);
  CU_ASSERT_EQUAL(*(int *)b->next->content, 3);

  CU_ASSERT_EQUAL(*(int *)a->content, 2);

  ft_lstclear(&a, free);
  ft_lstclear(&b, free);
}

void test_rra(void)
{
  t_list *a = ft_lstnew(to_ptr(1));
  ft_lstadd_back(&a, to_lst(2));
  ft_lstadd_back(&a, to_lst(3));

  rra(&a);

  CU_ASSERT_EQUAL(*(int *)a->content, 3);
  CU_ASSERT_EQUAL(*(int *)a->next->content, 1);
  CU_ASSERT_EQUAL(*(int *)a->next->next->content, 2);

  ft_lstclear(&a, free);
}

void test_rrb(void)
{
  t_list *b = ft_lstnew(to_ptr(1));
  ft_lstadd_back(&b, to_lst(2));
  ft_lstadd_back(&b, to_lst(3));

  rrb(&b);

  CU_ASSERT_EQUAL(*(int *)b->content, 3);
  CU_ASSERT_EQUAL(*(int *)b->next->content, 1);
  CU_ASSERT_EQUAL(*(int *)b->next->next->content, 2);

  ft_lstclear(&b, free);
}

void test_ra(void)
{
  t_list *a = ft_lstnew(to_ptr(1));
  ft_lstadd_back(&a, to_lst(2));
  ft_lstadd_back(&a, to_lst(3));

  ra(&a);

  CU_ASSERT_EQUAL(*(int *)a->content, 2);
  CU_ASSERT_EQUAL(*(int *)a->next->content, 3);
  CU_ASSERT_EQUAL(*(int *)a->next->next->content, 1);

  ft_lstclear(&a, free);
}

void test_rb(void)
{
  t_list *b = ft_lstnew(to_ptr(1));
  ft_lstadd_back(&b, to_lst(2));
  ft_lstadd_back(&b, to_lst(3));

  rb(&b);

  CU_ASSERT_EQUAL(*(int *)b->content, 2);
  CU_ASSERT_EQUAL(*(int *)b->next->content, 3);
  CU_ASSERT_EQUAL(*(int *)b->next->next->content, 1);

  ft_lstclear(&b, free);
}

void test_sa(void)
{
  t_list *a = ft_lstnew(to_ptr(1));

  sa(&a);

  CU_ASSERT_EQUAL(*(int *)a->content, 1);

  ft_lstadd_back(&a, to_lst(2));

  sa(&a);

  CU_ASSERT_EQUAL(*(int *)a->content, 2);
  CU_ASSERT_EQUAL(*(int *)a->next->content, 1);

  ft_lstclear(&a, free);
}

void test_sb(void)
{
  t_list *b = ft_lstnew(to_ptr(1));

  sb(&b);

  CU_ASSERT_EQUAL(*(int *)b->content, 1);

  ft_lstadd_back(&b, to_lst(2));

  sb(&b);

  CU_ASSERT_EQUAL(*(int *)b->content, 2);
  CU_ASSERT_EQUAL(*(int *)b->next->content, 1);

  ft_lstclear(&b, free);
}