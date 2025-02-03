/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:11:09 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/03 14:18:22 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CUnit/Basic.h>

extern "C"
{
#include "cmd.h"
}

void test_sa()
{
  t_list *a = NULL;
  t_list *b = NULL;
  int stack[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++)
  {
    int *elem = (int *)malloc(sizeof(int));
    *elem = stack[i];
    t_list *new_elem = ft_lstnew(elem);
    ft_lstadd_back(&a, new_elem);
  }
  sa(&a, &b);
  CU_ASSERT_EQUAL(*(int *)a->content, 2);

  int one = *(int *)a->content;
  int two = *(int *)a->next->content;
  int thre = *(int *)a->next->next->content;
  int forr = *(int *)a->next->next->next->content;
  int fiev = *(int *)a->next->next->next->next->content;

  CU_ASSERT_EQUAL(one, stack[1]);
  CU_ASSERT_EQUAL(two, stack[0]);
  CU_ASSERT_EQUAL(thre, stack[2]);
  CU_ASSERT_EQUAL(forr, stack[3]);
  CU_ASSERT_EQUAL(fiev, stack[4]);

  ft_lstclear(&a, free);
}

void test_sb()
{
  t_list *a = NULL;
  t_list *b = NULL;
  int stack[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++)
  {
    int *elem = (int *)malloc(sizeof(int));
    *elem = stack[i];
    t_list *new_elem = ft_lstnew(elem);
    ft_lstadd_back(&b, new_elem);
  }
  sb(&a, &b);
  CU_ASSERT_EQUAL(*(int *)b->content, 2);

  int one = *(int *)b->content;
  int two = *(int *)b->next->content;
  int thre = *(int *)b->next->next->content;
  int forr = *(int *)b->next->next->next->content;
  int fiev = *(int *)b->next->next->next->next->content;

  CU_ASSERT_EQUAL(one, stack[1]);
  CU_ASSERT_EQUAL(two, stack[0]);
  CU_ASSERT_EQUAL(thre, stack[2]);
  CU_ASSERT_EQUAL(forr, stack[3]);
  CU_ASSERT_EQUAL(fiev, stack[4]);

  ft_lstclear(&b, free);
}
