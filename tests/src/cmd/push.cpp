/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:40:16 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/03 13:47:28 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CUnit/Basic.h>

extern "C"
{
#include "cmd.h"
}

void test_pa()
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
  pa(&a, &b);
  CU_ASSERT_EQUAL(*(int *)a->content, 1);

  int i = 0;
  t_list *current = b;
  while (current)
  {
    int expected = stack[i + 1];
    CU_ASSERT_EQUAL(*(int *)current->content, expected);
    current = current->next;
    i++;
  }
  ft_lstclear(&a, free);
  ft_lstclear(&b, free);
}

void test_pb()
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
  pb(&a, &b);
  CU_ASSERT_EQUAL(*(int *)b->content, 1);

  int i = 0;
  t_list *current = a;
  while (current)
  {
    int expected = stack[i + 1];
    CU_ASSERT_EQUAL(*(int *)current->content, expected);
    current = current->next;
    i++;
  }
  ft_lstclear(&a, free);
  ft_lstclear(&b, free);
}
