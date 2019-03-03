/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:42:31 by yijhuang          #+#    #+#             */
/*   Updated: 2019/03/03 10:25:43 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fill(t_flist *cur, char **board, int coor[], int size)
{
	if (ft_fill_chk(cur, board, coor, size))
	{
		ft_fill_put(cur, board, coor[0], coor[1]);
		return (1);
	}
	return (0);
}

int		ft_fill_chk(t_flist *cur, char **board, int coor[], int size)
{
	int		i;
	int		j;
	char	sym;
	int		b_x;
	int		b_y;

	i = -1;
	j = 0;
	b_x = coor[0];
	b_y = coor[1];
	sym = cur->sym;
	if (board[coor[0]][coor[1]] != '.')
		return (0);
	while (++i < 4)
	{
		if (coor[0] + (cur->x)[i] >= size || coor[1] + (cur->y)[i]\
		>= size || coor[0] + (cur->x)[i] < 0 || coor[1] + (cur->y)[i]\
		< 0 || board[coor[0] + (cur->x)[i]][coor[1] + (cur->y)[i]] != '.')
			return (0);
	}
	return (1);
}

void	ft_fill_put(t_flist *cur, char **board, int yrow, int xcol)
{
	int	i;

	i = -1;
	while (++i < 4)
		board[yrow + (cur->x)[i]][xcol + (cur->y)[i]] = cur->sym;
}

void	ft_fill_remove(t_flist *cur, char **board, int yrow, int xcol)
{
	int	i;

	i = -1;
	while (++i < 4)
		board[yrow + (cur->x)[i]][xcol + (cur->y)[i]] = '.';
}

int		ft_backtracking(char **board, t_flist *cur, int size)
{
	int	coor[2];

	if (!cur)
		return (1);
	else
	{
		coor[0] = -1;
		while (++coor[0] < size)
		{
			coor[1] = -1;
			while (++coor[1] < size)
			{
				if (ft_fill(cur, board, coor, size))
				{
					if (ft_backtracking(board, cur->next, size))
						return (1);
					else
						ft_fill_remove(cur, board, coor[0], coor[1]);
				}
			}
		}
		return (0);
	}
}
