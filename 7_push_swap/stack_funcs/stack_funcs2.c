/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:32:08 by mlakenya          #+#    #+#             */
/*   Updated: 2021/12/12 17:32:11 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list **a)
{
	t_list	*tmp;
	t_list	*last_prev;

	if (!*a || !(*a)->next)
		return ;
	last_prev = *a;
	while (last_prev->next->next)
		last_prev = last_prev->next;
	last_prev->next->next = *a;
	*a = last_prev->next;
	last_prev->next = 0;
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	t_list	*tmp;
	t_list	*last_prev;

	if (!*b || !(*b)->next)
		return ;
	last_prev = *b;
	while (last_prev->next->next)
		last_prev = last_prev->next;
	last_prev->next->next = *b;
	*b = last_prev->next;
	last_prev->next = 0;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*last_prev;

	if (*a && (*a)->next)
	{
		last_prev = *a;
		while (last_prev->next->next)
			last_prev = last_prev->next;
		last_prev->next->next = *a;
		*a = last_prev->next;
		last_prev->next = 0;
	}
	if (*b && (*b)->next)
	{
		last_prev = *b;
		while (last_prev->next->next)
			last_prev = last_prev->next;
		last_prev->next->next = *b;
		*b = last_prev->next;
		last_prev->next = 0;
	}
	if ((*a && (*a)->next) || (*b && (*b)->next))
		write(1, "rrr\n", 4);
}

void	ra(t_list **a)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*a) || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	tmp = *a;
	*a = (*a)->next;
	last->next = tmp;
	tmp->next = 0;
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*b) || !(*b)->next)
		return ;
	last = *b;
	while (last->next)
		last = last->next;
	tmp = *b;
	*b = (*b)->next;
	last->next = tmp;
	tmp->next = 0;
	write(1, "rb\n", 3);
}
