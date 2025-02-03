/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arc_rotate.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:13:46 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/03 13:36:00 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CUnit/Basic.h>

extern "C"
{
#include "cmd.h"
}

void test_rra()
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
  rra(&a, &b);
  int i = 0;
  t_list *current = a;
  while (current)
  {
    int expected = i == 0 ? 5 : stack[i - 1];
    CU_ASSERT_EQUAL(*(int *)current->content, expected);
    current = current->next;
    i++;
  }

  ft_lstclear(&a, free);
}

void test_rrb()
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
  rrb(&a, &b);
  int i = 0;
  t_list *current = b;
  while (current)
  {
    int expected = i == 0 ? 5 : stack[i - 1];
    CU_ASSERT_EQUAL(*(int *)current->content, expected);
    current = current->next;
    i++;
  }

  ft_lstclear(&b, free);
}
