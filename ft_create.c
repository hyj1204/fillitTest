/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 05:00:51 by mikim             #+#    #+#             */
/*   Updated: 2019/03/02 21:45:50 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_format_board(char **board, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size)
		{
			board[i][j++] = '.';
		}
	}
}

char	**ft_create_board(int size)
{
	char	**board;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(board = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	board[size] = NULL;
	while (i < size)
	{
		if (!(board[i] = (char*)malloc(sizeof(char*) * (size + 1))))
			return (NULL);
		board[i][size] = '\0';
		i++;
	}
	ft_format_board(board, size);
	return (board);
}
