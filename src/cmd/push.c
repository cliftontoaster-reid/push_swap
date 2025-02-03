#include "cmd.h"

// Takes the first element at the top of b and puts it at the top of a.
// Does nothing if b is empty.
void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

// Takes the first element at the top of a and puts it at the top of b.
// Does nothing if a is empty.
void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}
