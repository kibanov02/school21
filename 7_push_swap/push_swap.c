/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:53:25 by mlakenya          #+#    #+#             */
/*   Updated: 2021/12/10 21:53:27 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_argv(char **argv, int *n, int argc)
{
	int	i;
	int	j;
	int	digit_num;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == 0)
			error();
		digit_num = 0;
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] <= '9' && argv[i][j] >= '0')
				digit_num++;
			else if (argv[i][j] != ' ' && argv[i][j] != '-')
				error();
		}
		*n += j;
		if (i + 1 != argc)
			(*n)++;
		if (digit_num == 0)
			error();
		i++;
	}
}

char	**refactor_args(char **argv, int argc, int n)
{
	char	*s;
	char	**nums;
	int		i;
	int		j;

	s = (char *)malloc(n + 1);
	if (!s)
		error();
	i = 1;
	n = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			s[n++] = argv[i][j++];
		if (i + 1 != argc)
			s[n++] = ' ';
		i++;
	}
	s[n] = 0;
	nums = ft_split(s, ' ');
	free(s);
	if (!nums)
		error();
	return (nums);
}

t_list	*parse_argv(int argc, char **argv)
{
	int		n;
	int		i;
	char	**nums;
	t_list	*a;

	n = 0;
	check_argv(argv, &n, argc);
	nums = refactor_args(argv, argc, n);
	i = 0;
	a = 0;
	while (nums[i])
	{
		if (!ft_list_push_back(&a, ft_atoi(nums[i])))
		{
			list_delete(a);
			free_mtx(nums);
			error();
		}
		i++;
	}
	return (a);
}

int	count_list(t_list *a)
{
	int	n;

	n = 0;
	while (a)
	{
		n++;
		a = a->next;
	}
	return (n);
}

void	sort_stack(t_stacks *s)
{
	int	flag;
	int	mid;
	int	k;
	int	i;

	mid = s->num;
	k = count_list(s->a);
	i = 0;
	while (i < k)
	{
		if (s->a->order <= s->num / 2)
			pb(&s->a, &s->b);
		else
			ra(&s->a);
		i++;
	}
	while (s->next < s->num)
	{
		flag = s->a->flag;
		while (s->a && s->a->flag == flag && s->next > 0)
		{
			if (s->a->order == s->next)
			{
				s->a->flag = -1;
				ra(&s->a);
				s->next++;
			}
			else
				pb(&s->a, &s->b);
		}
		while (s->b)
		{
			k = count_list(s->b);
			i = 0;
			flag++;
			mid = k / 2 + s->next;
			while (i < k)
			{
				s->b->flag = flag;
				if (s->b->order >= mid)
				{
					pa(&s->a, &s->b);
					if (s->a->order == s->next)
					{
						s->a->flag = -1;
						ra(&s->a);
						s->next++;
					}		
				}
				else if (s->b->order == s->next)
				{
					pa(&s->a, &s->b);
					s->a->flag = -1;
					ra(&s->a);
					s->next++;
				}	
				else
					rb(&s->b);
				i++;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	t_stacks	s;

	if (argc < 2)
		error();
	s.a = parse_argv(argc, argv);
	s.b = 0;
	s.next = 0;
	s.num = count_list(s.a);
	sort_stack(&s);
	print_stacks(s.a, s.b);
	print_indexes(s.a);
}
