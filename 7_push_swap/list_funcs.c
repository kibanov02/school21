/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:31:12 by mlakenya          #+#    #+#             */
/*   Updated: 2021/12/11 03:31:14 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_create_elem(int data, int index)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (0);
	list->data = data;
	list->order = index;
	list->flag = 0;
	list->next = NULL;
	return (list);
}

static int	check_data(t_list *list, int *n, int data)
{
	if (list->data == data)
		return (0);
	if (list->data > data)
		list->order++;
	else
		(*n)++;
	return (1);
}

t_list	*get_last(t_list *begin_list, int data, int *n)
{
	t_list	*list;

	list = begin_list;
	while (list->next)
	{
		if (!check_data(list, n, data))
			return (0);
		list = list->next;
	}
	return (list);
}

int	ft_list_push_back(t_list **begin_list, int data)
{
	t_list	*list;
	int		n;

	n = 0;
	if (*begin_list)
	{
		list = get_last(*begin_list, data, &n);
		if (!check_data(list, &n, data))
			return (0);
		list->next = ft_create_elem(data, n);
		if (!list->next)
			return (0);
	}
	else
	{
		*begin_list = ft_create_elem(data, n);
		if (!*begin_list)
			return (0);
	}
	return (1);
}

void	list_delete(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		if (tmp)
			free(tmp);
	}
}
