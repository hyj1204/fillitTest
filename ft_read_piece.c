/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:09:51 by yijhuang          #+#    #+#             */
/*   Updated: 2019/03/02 23:38:28 by yijhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_flist		*ft_read_piece(char *av)
{
	int		id;
	int		byte1;
	int		byte2;
	int		fd;
	char	buf1[21];
	char	buf2[2];
	t_flist	*head;

	id = 0;
	head = NULL;
	if ((fd = open(av, O_RDONLY)) < 0)
		ft_open_error();
	byte2 = -1;
	while ((byte1 = read(fd, buf1, 20)) > 0 || byte2 == 1)
	{
		buf1[20] = '\0';
		if (byte1 != 20)
			ft_byte_error();
		byte2 = read(fd, buf2, 1);
		buf2[1] = '\0';
		buf2[0] = '\0';
		head = ft_get_list(head, buf1, id++ + 65);
	}
	if (byte1 == 0 && byte2 == -1)
		ft_byte_error();
	return (head);
}

t_flist		*ft_get_list(t_flist *head, char buf[], char sym)
{
	char	**piece;
	t_flist	*t;

	piece = ft_to_piece(buf);
	if (!check_count(piece))
		ft_piece_num_error();
	t = new_fnode(piece, sym);
	free_two_char(piece);
	if (!check_relate(t->x, t->y))
		ft_error();
	head = append_fnode(head, t);
	return (head);
}

char	**ft_to_piece(char buf[])
{
	char	**piece;
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	piece = ft_create_board(4);
	while (piece[++i])
	{
		j = -1;
		while (++j < 4)
		{
			piece[i][j] = buf[k++];
		}
		k++;
		piece[i][j] = '\0';
	}
	return (piece);
}
