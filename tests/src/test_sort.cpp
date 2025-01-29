/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:05:27 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/29 20:16:14 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUnit/Basic.h"

#define BLK "\033[0;30m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYN "\033[0;36m"
#define WHT "\033[0;37m"
#define COLOR_RESET "\033[0m"

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

    ft_printf("%sWorker started%s\n", CYN, COLOR_RESET);
    for (int round = 0; round < rounds; round++)
    {
      t_human *human = (t_human *)calloc(1, sizeof(t_human));
      int amount = (rand() % 201) + 10;
      ft_printf("%sStarting testing at idx: %d size: %d%s\n", RED, round, amount, COLOR_RESET);

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
      ft_printf("%sTest idx %d ended\n%s", GRN, round, COLOR_RESET);
    }
    ft_printf("%sWorker finished%s\n", BLU, COLOR_RESET);
  };
  std::vector<std::thread> pool;
  pool.reserve(thread_count);

  for (int i = 0; i < thread_count; i++)
    pool.emplace_back(worker);

  for (auto &t : pool)
    t.join();
}
