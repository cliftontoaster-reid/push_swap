/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:09:53 by lfiorell          #+#    #+#             */
/*   Updated: 2025/02/03 17:17:20 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUnit/Basic.h"

extern "C"
{
#include "job.h"
}

void test_quicksort(void)
{
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  quicksort(arr, 0, n - 1);
  CU_ASSERT_EQUAL(arr[0], 1);
  CU_ASSERT_EQUAL(arr[1], 5);
  CU_ASSERT_EQUAL(arr[2], 7);
  CU_ASSERT_EQUAL(arr[3], 8);
  CU_ASSERT_EQUAL(arr[4], 9);
  CU_ASSERT_EQUAL(arr[5], 10);
}