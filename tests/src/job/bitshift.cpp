/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitshift.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:11:52 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/06 12:03:25 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUnit/Basic.h"

extern "C"
{
#include "job.h"
#include <time.h>
}

void nokill(void *content)
{
  (void)content;
}

void test_int_get_bit(void)
{
  CU_ASSERT_EQUAL(int_get_bit(0b1010, 0), 0);
  CU_ASSERT_EQUAL(int_get_bit(0b1010, 1), 1);
  CU_ASSERT_EQUAL(int_get_bit(0b1010, 2), 0);
  CU_ASSERT_EQUAL(int_get_bit(0b1010, 3), 1);
}

void test_get_max_bits(void)
{
  t_list *stack = NULL;
  int max_bits;

  max_bits = get_max_bits(stack);
  CU_ASSERT_EQUAL(max_bits, 0);

  int a = 0b1010;
  stack = ft_lstnew(&a);
  max_bits = get_max_bits(stack);
  CU_ASSERT_EQUAL(max_bits, 4);

  int b = 0b101;
  ft_lstadd_back(&stack, ft_lstnew(&b));
  max_bits = get_max_bits(stack);
  CU_ASSERT_EQUAL(max_bits, 4);

  int c = 0b100000;
  ft_lstadd_back(&stack, ft_lstnew(&c));
  max_bits = get_max_bits(stack);
  CU_ASSERT_EQUAL(max_bits, 6);

  ft_lstclear(&stack, nokill);
}

void test_bitshift(void)
{
  t_data *data = init_thatguy();
  int values[10] = {
      0b101, 0b111, 0b1010, 0b100, 0b1, 0b1001, 0b10, 0b1000, 0b11, 0b110};

  for (int i = 0; i < 10; i++)
  {
    int *num = (int *)malloc(sizeof(int));
    *num = values[i];
    ft_lstadd_back(&data->a, ft_lstnew(num));
  }

  bitshift(data);

  int count = 0;
  t_list *tmp = data->a;
  while (tmp)
  {
    count++;
    tmp = tmp->next;
  }
  CU_ASSERT_EQUAL(count, 10);

  // Check if the stack is sorted in ascending order
  int sorted = 1;
  tmp = data->a;
  while (tmp && tmp->next)
  {
    if (*(int *)(tmp->content) > *(int *)(tmp->next->content))
    {
      sorted = 0;
      break;
    }
    tmp = tmp->next;
  }
  CU_ASSERT(sorted);

  kill_thatguy(data);
}

void test_bitshift_random_once(void)
{
  t_data *data = init_thatguy();

  // Generate a random size for the array
  int size = rand() % 499 + 2;
  int *values = (int *)malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++)
  {
    int num;
    bool duplicate;
    do
    {
      num = rand() % 1024;
      duplicate = false;
      for (int j = 0; j < i; j++)
      {
        if (values[j] == num)
        {
          duplicate = true;
          break;
        }
      }
    } while (duplicate);
    values[i] = num;
  }

  // Push the random unique items
  for (int i = 0; i < size; i++)
  {
    int *num = (int *)malloc(sizeof(int));
    *num = values[i];
    ft_lstadd_back(&data->a, ft_lstnew(num));
  }
  free(values);

  bitshift(data);

  // Check the final list length
  int count = 0;
  t_list *tmp = data->a;
  while (tmp)
  {
    count++;
    tmp = tmp->next;
  }
  if (count != size)
  {
    printf("Expected size: %d, Actual size: %d\n", size, count);
    CU_FAIL("List size mismatch");
  }
  else
  {
    CU_PASS("List size matches");
  }

  // Check if the stack is sorted
  int sorted = 1;
  tmp = data->a;
  while (tmp && tmp->next)
  {
    if (*(int *)tmp->content > *(int *)tmp->next->content)
    {
      sorted = 0;
      break;
    }
    tmp = tmp->next;
  }

  if (!sorted)
  {
    printf("List is not sorted!\n");
    tmp = data->a;
    while (tmp)
    {
      printf("%d ", *(int *)tmp->content);
      tmp = tmp->next;
    }
    printf("\n");
    CU_FAIL("List is not sorted");
  }
  else
  {
    CU_PASS("List is sorted");
  }

  kill_thatguy(data);
}

void test_bitshift_random(void)
{
  srand(time(NULL));
  for (int i = 0; i < 150; i++)
  {
    test_bitshift_random_once();
  }
}
