/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:22:43 by mlakenya          #+#    #+#             */
/*   Updated: 2021/10/25 17:22:45 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_str_before_n(char *s)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	res = (char *)malloc(i + 2);
	if (!res)
		return (0);
	ft_strlcpy(res, s, i + 1);
	if (s[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	*get_str_after_n(char *s)
{
	int		i;
	char	*res;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
		return (0);
	j = 0;
	while (s[i++])
		j++;
	res = (char *)malloc(i + 1);
	if (!res)
		return (0);
	ft_strlcpy(res, s + i + 1, j + 1);
	return (res);
}

static char	*read_line(int fd, char *s)
{
	char	*buff;
	char	*temp;
	int		i;

	buff = (char *)malloc(BUFFER_SIZE);
	if (!buff)
		return (0);
	while (!ft_strchr(s, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (!i)
			break ;
		if (!s)
		{
			s = ft_strdup(buff);
			if (!s)
				return (0);
		}
		else
		{
			buff[i] = 0;
			temp = s;
			s = ft_strjoin(s, buff);
			if (!s)
				return (0);
			if (temp)
				free(temp);
		}
		free(buff);
		buff = (char *)malloc(BUFFER_SIZE);
		if (!buff)
			return (0);
	}
	free(buff);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*res;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	s = read_line(fd, s);
	if (!s)
		return (0);
	if (!*s)
	{
		free(s);
		s = 0;
		return (0);
	}
	res = get_str_before_n(s);
	temp = get_str_after_n(s);
	free(s);
	s = temp;
	return (res);
}
/*
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("a.txt", O_RDONLY);
	for (int i = 0; i < 6; i++)
		printf("%s", get_next_line(fd));
}
*/