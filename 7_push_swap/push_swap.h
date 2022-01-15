/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 01:26:40 by mlakenya          #+#    #+#             */
/*   Updated: 2021/12/11 01:26:42 by mlakenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				data;
	int				order;
	int				flag;
	struct s_list	*next;
}			t_list;

typedef struct s_stack
{
	struct s_list	*a;
	struct s_list	*b;
	int				next;
	int				num;
}			t_stacks;

char			**ft_split(char const *s, char c);
int				ft_atoi(const char *str);
void			error(void);
char			**free_mtx(char **mtx);
int				ft_list_push_back(t_list **begin_list, int data);
void			list_delete(t_list *list);

//stack:
void			sa(t_list	**a);
void			sb(t_list	**b);
void			ss(t_list	**a, t_list	**b);
void			pb(t_list **a, t_list **b);
void			pa(t_list **a, t_list **b);
void			rra(t_list **a);
void			rrb(t_list **b);
void			rrr(t_list **a, t_list **b);
void			ra(t_list **a);
void			rb(t_list **b);
void			rr(t_list **a, t_list **b);

//debug:
void			print_stacks(t_list *a, t_list *b);
void			print_indexes(t_list *a);

#endif
