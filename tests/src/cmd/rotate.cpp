/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:48:23 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/03 14:03:51 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CUnit/Basic.h>

extern "C"
{
#include "cmd.h"
}

static void printilst(t_list *lst)
{
  t_list *current = lst;
  while (current)
  {
    printf("%d ", *(int *)current->content);
    current = current->next;
  }
}

void test_ra()
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
  ra(&a, &b);
  printilst(a);
  int i = 0;
  t_list *current = a;
  while (current)
  {
    int expected = i == 4 ? 1 : stack[i + 1];
    CU_ASSERT_EQUAL(*(int *)current->content, expected);
    current = current->next;
    i++;
  }

  ft_lstclear(&a, free);
}

void test_rb(void)
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
  rb(&a, &b);
  int i = 0;
  t_list *current = b;
  while (current)
  {
    int expected = i == 4 ? 1 : stack[i + 1];
    CU_ASSERT_EQUAL(*(int *)current->content, expected);
    current = current->next;
    i++;
  }

  ft_lstclear(&b, free);
}