/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:47:00 by mlakenya          #+#    #+#             */
/*   Updated: 2021/06/28 21:00:52 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	my_isspace(char ch)
{
	if (ch == ' '
		|| ch == '\f'
		|| ch == '\n'
		|| ch == '\r'
		|| ch == '\t'
		|| ch == '\v')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	while (my_isspace(str[i]) != 0)
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n *= 10;
		n += str[i] - '0';
		i++;
	}
	return (n * sign);
}
