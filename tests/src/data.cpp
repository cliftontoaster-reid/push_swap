/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:46:32 by lfiorell          #+#    #+#             */
/*   Updated: 2025/01/22 18:09:28 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CUnit/CUnit.h>

extern "C"
{
#include "data.h"
#include "libft.h"
}

void test_parse_list_args(void)
{
  int argc = 4;
  char const *argv[] = {"push_swap", "1", "2", "3"};
  t_list *list = NULL;

  CU_ASSERT_EQUAL(parse_list_args(argc, argv, &list), 1);

  CU_ASSERT_EQUAL(*(int *)list->content, 1);
  CU_ASSERT_EQUAL(*(int *)list->next->content, 2);
  CU_ASSERT_EQUAL(*(int *)list->next->next->content, 3);

  ft_lstclear(&list, free);
}

void test_parse_list_envp(void)
{
  const char *envp[] = {"ARG=1 2 3", NULL};
  t_list *list = NULL;

  CU_ASSERT_EQUAL(parse_list_envp((char *const *)envp, &list), 1);

  CU_ASSERT_EQUAL(*(int *)list->content, 1);
  CU_ASSERT_EQUAL(*(int *)list->next->content, 2);
  CU_ASSERT_EQUAL(*(int *)list->next->next->content, 3);

  ft_lstclear(&list, free);
}

void test_init_data_envp(void)
{
  int argc = 4;
  char const *argv[] = {"push_swap", "1", "2", "3"};
  const char *envp[] = {"ARG=1 5 3", NULL};

  t_human *data = ft_init_data(argc, argv, (char *const *)envp);

  CU_ASSERT_PTR_NOT_NULL(data);
  CU_ASSERT_EQUAL(*(int *)data->a->content, 1);
  CU_ASSERT_EQUAL(*(int *)data->a->next->content, 5);
  CU_ASSERT_EQUAL(*(int *)data->a->next->next->content, 3);

  ft_kill_all_humans(data);
}

void test_init_data_args(void)
{
  int argc = 4;
  char const *argv[] = {"push_swap", "1", "2", "3"};
  const char *envp[] = {"OwO=Useless", NULL};

  t_human *data = ft_init_data(argc, argv, (char *const *)envp);

  CU_ASSERT_PTR_NOT_NULL(data);
  CU_ASSERT_EQUAL(*(int *)data->a->content, 1);
  CU_ASSERT_EQUAL(*(int *)data->a->next->content, 2);
  CU_ASSERT_EQUAL(*(int *)data->a->next->next->content, 3);

  ft_kill_all_humans(data);
}

void test_init_data_failure(void)
{
  int argc = 4;
  char const *argv[] = {"push_swap"};
  const char *envp[] = {"GAY=1 5 3", NULL};

  t_human *data = ft_init_data(argc, argv, (char *const *)envp);

  CU_ASSERT_PTR_NULL(data);
}