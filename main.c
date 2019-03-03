/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 21:54:43 by yijhuang          #+#    #+#             */
/*   Updated: 2019/03/03 10:24:51 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_flist	*read_file_piece(char *fname)
{
	t_flist *head;

	head = NULL;
	head = ft_read_piece(fname);
	return (head);
}

int	main(int argc, char **argv)
{
	char	**board;
	int		pcs;
	t_flist	*head;
	int		reg;
	int		size;

	if (argc == 1)
		ft_usage();
	else
	{
		reg = 0;
		size = 0;
		head = read_file_piece(argv[1]);
		pcs =  ft_get_list_length(head);
		while (size * size < pcs * 4)
			size++;
		while (reg == 0)
		{
			board = ft_create_board(size);
			reg = ft_backtracking(board, head, size);
			if (reg == 1)
				break ;
			free_two_char(board);
			size++;
		}
		free_list(head);
		ft_print(board);
		free_two_char(board);
	}
	return (0);
}
