/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:31:58 by mlakenya          #+#    #+#             */
/*   Updated: 2021/12/12 17:32:00 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list	**a)
{
	t_list	*tmp;

	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	tmp->next = (*a);
	*a = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_list	**b)
{
	t_list	*tmp;

	tmp = (*b)->next;
	(*b)->next = (*b)->next->next;
	tmp->next = (*b);
	*b = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_list	**a, t_list	**b)
{
	t_list	*tmp;

	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	tmp->next = (*a);
	*a = tmp;
	tmp = (*b)->next;
	(*b)->next = (*b)->next->next;
	tmp->next = (*b);
	*b = tmp;
	write(1, "ss\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a == 0)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b == 0)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}
