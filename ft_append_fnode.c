/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_append_fnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 21:44:38 by xinzhang          #+#    #+#             */
/*   Updated: 2019/03/03 10:20:28 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_point(char **tet, int *ycnt, int *xcnt)
{
	int x;
	int y;

	y = -1;
	while (tet[++y] != NULL)
	{
		x = -1;
		while (tet[y][++x] != '\0')
			if (tet[y][x] != '.')
				if (*ycnt > y)
					*ycnt = y;
	}
	if (*ycnt == 4)
		return (-1);
	else
	{
		x = -1;
		while (tet[*ycnt][++x])
			if (tet[*ycnt][x] != '.')
				if (*xcnt > x)
					*xcnt = x;
	}
	return (1);
}

// void	ft_get_xy(char **p, int *x, int *y)
// {
// 	int	co_x;
// 	int	co_y;
// 	int loop_x;
// 	int	loop_y;
// 	int	index;

// 	co_x = 4;
// 	co_y = 4;
//     ft_check_point(p, &co_x, &co_y);
//     loop_x = co_x;
//     index = 0;
//     ft_get_xy_helper(p, x, y, co_x, co_y);
	
// 	x[index] = co_x;
// 	y[index] = co_y;
// }

// void	ft_get_xy_helper(char **p, int *x, int *y, int	co_x, int co_y)
// {
// 	int	loop_x;
// 	int	loop_y;
// 	int	index;
	
// 	loop_x =co_x;
// 	loop_y = 0;
// 	index = 0;
// 	while (p[loop_x] && index < 4)
// 	{
// 		loop_y = -1;
// 		while (p[loop_x][++loop_y] && index < 4)
// 		{
// 			if (p[loop_x][loop_y] == '#')
// 			{
// 				x[index] = loop_x - co_x;
// 				y[index] = loop_y - co_y;
// 				index++;
// 			}
// 		}
// 		loop_x++;
// 	}
// 	x[index] = co_x;
// 	y[index] = co_y;
// }

// void	ft_get_xy(char **p, int *x, int *y)
// {
// 	int	val[5];

// 	val[0] = 4;
// 	val[1] = 4;
// 	ft_check_point(p, &val[0], &val[1]);
// 	val[2] = val[0];
// 	val[4] = 0;
// 	while (p[val[2]] && val[4] < 4)
// 	{
// 		val[3] = 0;
// 		while (p[val[2]][val[3]] && val[4] < 4)
// 		{
// 			if (p[val[2]][val[3]] == '#')
// 			{
// 				x[val[4]] = val[2] - val[0];
// 				x[val[4]] = val[3] - val[1];
// 				val[4]++;
// 			}
// 			val[3]++;
// 		}
// 		val[2]++;
// 	}
// 	x[val[4]] = val[0];
// 	y[val[4]] = val[1];
// }

void	ft_get_xy(char **p, int *x, int *y)
{
	int	co_x;
	int	co_y;
	int loop_x;
	int	loop_y;
	int	index;

	co_x = 4;
	co_y = 4;
	ft_check_point(p, &co_x, &co_y);
	loop_x = co_x;
	index = 0;
	while (p[loop_x] && index < 4)
	{
		loop_y = 0;
		while (p[loop_x][loop_y] && index < 4)
		{
			if (p[loop_x][loop_y] == '#')
			{
				x[index] = loop_x - co_x;
				y[index] = loop_y - co_y;
				index++;
			}
			loop_y++;
		}
		loop_x++;
	}
	x[index] = co_x;
	y[index] = co_y;
}

t_flist	*new_fnode(char **v, char sym)
{
	t_flist *tf;

	tf = (t_flist *)malloc(sizeof(t_flist));
	if (!tf)
		return (NULL);
	ft_get_xy(v, tf->x, tf->y);
	tf->sym = sym;
	tf->next = NULL;
	return (tf);
}

t_flist	*append_fnode(t_flist *head, t_flist *node)
{
	t_flist	*tmp;
	
	if (!head)
		return (node);
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
		return (head);
	}
}

int	ft_get_list_length(t_flist *list)
{
	int i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
