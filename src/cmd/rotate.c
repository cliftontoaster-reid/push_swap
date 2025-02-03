#include "cmd.h"

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	(void)b;
	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	(void)a;
	if (!b || !*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

// Perform ra and rb simultaneously.
void	rr(t_list **a, t_list **b)
{
	ra(a, b);
	rb(a, b);
}
