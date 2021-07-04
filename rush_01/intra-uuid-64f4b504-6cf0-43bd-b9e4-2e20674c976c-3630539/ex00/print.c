/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpunishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:15:24 by dpunishe          #+#    #+#             */
/*   Updated: 2021/07/04 19:15:31 by dpunishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	stampa(int board[4][4])
{
	int	rig;
	int	col;

	rig = 0;
	col = 0;
	while (rig < 4)
	{
		col = 0;
		while (col < 4)
		{
			ft_putchar(board[rig][col] + '0');
			if (col != 3)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		rig++;
	}
}
