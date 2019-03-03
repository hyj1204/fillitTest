/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:37:43 by yijhuang          #+#    #+#             */
/*   Updated: 2019/03/02 22:41:04 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_two_char(char **b)
{
	int i;

	i = -1;
	if (b && *b)
	{
		while (b[++i])
			free(b[i]);
	}
	free(b);
}

void	free_list(t_flist *list)
{
	t_flist *tmp;

	while (list)
	{
		tmp = list;
		free(tmp);
		list = list->next;
	}
}
