int	check_next(t_stacks* s)
{
	if (s->a->order == s->next)
	{
		s->a->flag = -1;
		ra(&s->a);
		s->next++;
		return (1);
	}
	return (0);
}

void	empty_b(t_stacks *s, int flag, int i, int k)
{
	int	mid;

	while (s->b)
	{
		k = count_list(s->b);
		i = 0;
		flag++;
		mid = k / 2 + s->next;
		while (i++ < k)
		{
			s->b->flag = flag;
			if (s->b->order >= mid)
			{
				pa(&s->a, &s->b);
				check_next(s);
			}
			else if (s->b->order == s->next)
			{
				pa(&s->a, &s->b);
				check_next(s);
			}
			else
				rb(&s->b);
		}
	}
}

void	sort_stack(t_stacks* s)
{
	int	flag;
	int	k;
	int	i;

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
			if (!check_next(s))
				pb(&s->a, &s->b);
		empty_b(s, flag, 0, 0);
	}
}