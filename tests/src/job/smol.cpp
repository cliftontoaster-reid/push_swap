/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smol.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:09:17 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/05 16:25:51 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CUnit/Basic.h>

extern "C"
{
#include "job.h"
}

static void print_list(t_list *lst)
{
  ft_printf("\nList: ");
  while (lst)
  {
    printf("%d, ", *(int *)lst->content);
    lst = lst->next;
  }
  printf("\n");
}

static int is_sorted(t_list *lst)
{
  if (!lst)
    return 1;
  int *prev = (int *)lst->content;
  lst = lst->next;
  while (lst)
  {
    int *curr = (int *)lst->content;
    if (*prev > *curr)
      return (0);
    prev = curr;
    lst = lst->next;
  }
  return (1);
}

void test_sort_two(void)
{
  t_data *data = init_thatguy();
  int *a = (int *)malloc(sizeof(int));
  *a = 3;
  int *b = (int *)malloc(sizeof(int));
  *b = 2;

  ft_lstadd_back(&data->a, ft_lstnew(a));
  ft_lstadd_back(&data->a, ft_lstnew(b));

  sort_two(data);

  if (is_sorted(data->a) == 0)
  {
    print_list(data->a);
    CU_FAIL("List is not sorted");
  }
  else
    CU_PASS("List is sorted");

  kill_thatguy(data);
}

void test_sort_three(void)
{
  t_data *data = init_thatguy();
  int *a = (int *)malloc(sizeof(int));
  int *b = (int *)malloc(sizeof(int));
  int *c = (int *)malloc(sizeof(int));
  *a = 3;
  *b = 2;
  *c = 1;

  ft_lstadd_back(&data->a, ft_lstnew(a));
  ft_lstadd_back(&data->a, ft_lstnew(b));
  ft_lstadd_back(&data->a, ft_lstnew(c));

  sort_three(data);

  if (is_sorted(data->a) == 0)
  {
    print_list(data->a);
    CU_FAIL("List is not sorted");
  }
  else
    CU_PASS("List is sorted");

  kill_thatguy(data);
}

void test_sort_four(void)
{
  t_data *data = init_thatguy();
  int *a = (int *)malloc(sizeof(int));
  int *b = (int *)malloc(sizeof(int));
  int *c = (int *)malloc(sizeof(int));
  int *d = (int *)malloc(sizeof(int));
  *a = 3;
  *b = 2;
  *c = 1;
  *d = 4;

  ft_lstadd_back(&data->a, ft_lstnew(a));
  ft_lstadd_back(&data->a, ft_lstnew(b));
  ft_lstadd_back(&data->a, ft_lstnew(c));
  ft_lstadd_back(&data->a, ft_lstnew(d));

  sort_four(data);

  if (is_sorted(data->a) == 0)
  {
    print_list(data->a);
    CU_FAIL("List is not sorted");
  }
  else
    CU_PASS("List is sorted");

  kill_thatguy(data);
}
