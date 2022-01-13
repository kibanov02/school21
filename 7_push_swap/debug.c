/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:03:35 by mlakenya          #+#    #+#             */
/*   Updated: 2021/12/12 15:03:36 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list *a, t_list *b)
{
	t_list	*prnt;

	printf("Stack a:\n");
	prnt = a;
	while (prnt)
	{
		printf("%d ", prnt->data);
		prnt = prnt->next;
	}
	printf("\nStack b:\n");
	prnt = b;
	while (prnt)
	{
		printf("%d ", prnt->data);
		prnt = prnt->next;
	}
	printf("\n");
}

void	print_indexes(t_list *a)
{
	t_list	*ptr;

	ptr = a;
	printf("\na indexes: \n");
	while (ptr)
	{
		printf("%d ", ptr->order);
		ptr = ptr->next;
	}
	printf("\n");
}
