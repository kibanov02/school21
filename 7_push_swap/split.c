/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:28:35 by mlakenya          #+#    #+#             */
/*   Updated: 2021/10/12 21:28:37 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**free_mtx(char **mtx)
{
	int	j;

	j = 0;
	while (mtx[j])
		free(mtx[j++]);
	free(mtx);
	return (0);
}

unsigned long	get_num_of_letters(char const *s, char c, unsigned long *i)
{
	unsigned long	n;

	n = 0;
	while (s[*i] && s[*i] != c)
	{
		n++;
		*i += 1;
	}
	return (n);
}

char	**ft_split2(char const *s, char c, char **res, unsigned long i)
{
	unsigned long	k;
	unsigned long	j;
	unsigned long	n;

	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		n = get_num_of_letters(s, c, &i);
		res[k] = (char *)malloc((n + 1) * sizeof(char));
		if (!res[k])
			return (free_mtx(res));
		j = 0;
		i -= n;
		while (j < n)
			res[k][j++] = s[i++];
		res[k++][j] = 0;
	}
	res[k] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	unsigned long	n;
	unsigned long	i;
	char			**res;

	if (!s)
		return (0);
	n = 1;
	i = 0;
	while (s[i])
		if (s[i++] == c)
			n++;
	res = (char **)malloc((n + 1) * sizeof(char *));
	if (res == 0)
		return (0);
	return (ft_split2(s, c, res, 0));
}
