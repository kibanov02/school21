/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:32:15 by mlakenya          #+#    #+#             */
/*   Updated: 2021/12/12 17:32:17 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	if ((*a) && (*a)->next)
	{
		last = *a;
		while (last->next)
			last = last->next;
		tmp = *a;
		*a = (*a)->next;
		last->next = tmp;
		tmp->next = 0;
	}
	if ((*b) && (*b)->next)
	{
		last = *b;
		while (last->next)
			last = last->next;
		tmp = *b;
		*b = (*b)->next;
		last->next = tmp;
		tmp->next = 0;
	}
	if (((*a) && (*a)->next) || ((*b) && (*b)->next))
		write(1, "rr\n", 3);
}
