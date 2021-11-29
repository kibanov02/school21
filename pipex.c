/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:54:46 by mlakenya          #+#    #+#             */
/*   Updated: 2021/11/27 16:54:48 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long	get_num_of_words(char const *s, char c)
{
	unsigned long	n;
	unsigned long	i;

	n = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			n++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
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

int	ft_split2(char const *s, char c, char **res)
{
	unsigned long	k;
	unsigned long	i;
	unsigned long	j;
	unsigned long	n;

	i = 0;
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
			return (0);
		j = 0;
		i -= n;
		while (j < n)
			res[k][j++] = s[i++];
		res[k++][j] = 0;
	}
	res[k] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	unsigned long	n;
	char			**res;

	if (!s)
		return (0);
	n = get_num_of_words(s, c);
	res = (char **)malloc((n + 1) * sizeof(char *));
	if (res == 0)
		return (0);
	if (!ft_split2(s, c, res))
		return (0);
	return (res);
}

unsigned long	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

char	*ft_substr(char const *s, unsigned int start, unsigned long len)
{
	unsigned int	len_s;
	char			*ptr;
	char			*res;

	if (!s || start < 0)
		return (0);
	len_s = ft_strlen(s);
	if (start >= len_s)
		len = 0;
	if (len_s - start < len)
		len = len_s - start;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	res = ptr;
	s += start;
	while (*s && len--)
		*ptr++ = *s++;
	*ptr = '\0';
	return (res);
}

char	*ft_join(char const *s1, char const *s2)
{
	unsigned long	len;
	char			*ptr;
	char			*res;

	len = 0;
	ptr = (char *)s1;
	while (*ptr++)
		len++;
	ptr = (char *)s2;
	while (*ptr++)
		len++;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	res = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = 0;
	return (res);
}

















char	**parse_envp(char *envp)
{
	char	*paths;
	char	**res;

	paths = ft_substr(envp, 5, 100000);
	res = ft_split(paths, ':');
	free(paths);
	return (res);
}


int	execute(char **paths, char *cmd_with_args, char **envp)
{
	char	**arg;
	char	*cmd;
	char	*tmp;
	int		i;

	arg = ft_split(cmd_with_args, ' ');

	i = -1;
	while (paths[++i])
	{
		cmd = ft_join(paths[i], "/");
		tmp = cmd;
		cmd = ft_join(cmd, arg[0]);
		free(tmp);
		execve(cmd, arg, envp);
		free(cmd);
	}
	return (0);
}

void	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int		end[2];
	pid_t	parent;
	int		status;

	pipe(end);
	parent = fork();
	if (parent < 0)
		return (perror("Fork: "));
	if (!parent)
	{
		dup2(fd1, STDIN_FILENO);
		dup2(end[1], STDOUT_FILENO);
		close(end[0]);
		close(fd1);
		execute(parse_envp(envp[13]), argv[2], envp);
		exit(1);
	}
	else
	{
		waitpid(-1, &status, 0);
		dup2(fd2, STDOUT_FILENO);
		dup2(end[0], STDIN_FILENO);
		close(end[1]);
		close(fd2);
		execute(parse_envp(envp[13]), argv[3], envp);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;

	if (argc != 5)
	{
		write(1, "pipex: there should be 4 arguments\n", 35);
		return (0);
	}
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0)
	{
		ft_putstr("pipex: no such file or directory: ");
		ft_putstr(argv[1]);
		write(1, "\n", 1);
		return (0);
	}
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd2 < 0)
	{
		ft_putstr("pipex: permission denied: ");
		ft_putstr(argv[4]);
		write(1, "\n", 1);
		return (0);
	}
	pipex(fd1, fd2, argv, envp);
}
