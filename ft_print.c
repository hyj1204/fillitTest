/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 05:00:14 by mikim             #+#    #+#             */
/*   Updated: 2017/03/17 15:45:33 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_usage(void)
{
	write(1, "usage: ./fillit <FILE>\n", 23);
	exit(0);
}

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void	ft_print(char **res)
{
	int x;
	int y;

	y = -1;
	while (res[++y] != NULL)
	{
		x = -1;
		while (res[y][++x])
			write(1, &res[y][x], 1);
		write(1, "\n", 1);
	}
}

void	ft_print_list(t_flist **list)
{
	t_flist	*tmp;

	tmp = *list;
	int i;
	if (list && tmp)
	{
		while (tmp)
		{
			i = -1;
			printf("the origin point\n%d, %d %c\n", (tmp->x)[4], (tmp->y)[4],tmp->sym);
			while (++i < 4)
				printf("%d, %d\n", (tmp->x)[i], (tmp->y)[i]);
			tmp = tmp->next;
		}
	}
}