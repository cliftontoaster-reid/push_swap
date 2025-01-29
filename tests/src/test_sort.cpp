/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:05:27 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/29 17:30:43 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUnit/Basic.h"

extern "C"
{
#include "libft.h"
#include "utils.h"
#include "pretzel.h"
#include "nbr.h"
#include <climits>
}

static void fuck_no(void *c)
{
  (void)c;
}

int is_sorted(t_list *lst)
{
  while (lst && lst->next)
  {
    if (*(int *)lst->content > *(int *)lst->next->content)
      return 0;
    lst = lst->next;
  }
  return 1;
}

#include <thread>
#include <vector>

void test_pretzel(void)
{
  const int thread_count = std::thread::hardware_concurrency() ? std::thread::hardware_concurrency() : 1;

  auto worker = []()
  {
    int rounds = 100;

    for (int round = 0; round < rounds; round++)
    {
      ft_printf("Test iteration %d is running\n", round);
      t_human *human = (t_human *)calloc(1, sizeof(t_human));
      int amount = (rand() % 201) + 10;

      for (int j = 0; j < amount; j++)
      {
        int *nbr = (int *)malloc(sizeof(int));
        *nbr = rand() % 100;
        ft_lstadd_back(&human->a, ft_lstnew(nbr));
      }

      t_list *aaa = (t_list *)clone_list(human->a);

      pretzel(human);

      CU_ASSERT_EQUAL(is_sorted(human->a), 1);

      if (is_sorted(human->a) != 1)
      {
        ft_printf("Starting with: ");
        for (t_list *tmp = aaa; tmp; tmp = tmp->next)
          ft_printf("%d ", *(int *)tmp->content);
        ft_printf("\nOwO not cool\n");
        print_stacks(human);
      }

      ft_lstclear(&aaa, fuck_no);
      ft_kill_all_humans(human);
    }
  };
  std::vector<std::thread> pool;
  pool.reserve(thread_count);

  for (int i = 0; i < thread_count; i++)
    pool.emplace_back(worker);

  for (auto &t : pool)
    t.join();
}
