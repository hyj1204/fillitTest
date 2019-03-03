#include "fillit.h"

int    ft_fill(t_flist *cur, char **board, int yrow, int xcol, int size)
{
    if (ft_fill_chk(cur, board, yrow, xcol, size))
    {
//		printf("before fill the block\n");
        ft_fill_put(cur, board, yrow, xcol);
//		ft_print(board);
//		printf("finished fill\n");
        return (1);
    }
    return (0);
}

int		ft_fill_chk(t_flist *cur, char **board, int yrow, int xcol, int size)
{
	int	i;
	int j;
	char sym;
	int b_x;
	int b_y;

	i = -1;
	j = 0;
	b_x = yrow;
	b_y = xcol;
	sym = cur->sym;
	if (board[yrow][xcol] != '.')
		return (0);
	while(++i < 4)
	{
		// b_x += (cur->x)[i];
		// b_y += (cur->y)[i];
//        printf(" %d, %d\n",(cur->x)[i], (cur->y)[i]);
		if (yrow + (cur->x)[i] >= size || xcol + (cur->y)[i] >= size || yrow + \
         (cur->x)[i] < 0 || xcol + (cur->y)[i] < 0 || board[yrow + \
         (cur->x)[i]][xcol + (cur->y)[i]] != '.')
		{
			return (0);
        }
	}
	return (1);
}

void		ft_fill_put(t_flist *cur, char **board, int yrow, int xcol)
{
	int	i;
	
	i = -1;
	while(++i < 4)
		board[yrow + (cur->x)[i]][xcol + (cur->y)[i]] = cur->sym;
}

void		ft_fill_remove(t_flist *cur, char **board, int yrow, int xcol)
{
	int	i;
	
	i = -1;
	while(++i < 4)
		board[yrow + (cur->x)[i]][xcol + (cur->y)[i]] = '.';
}

int ft_backtracking(char **board, t_flist *cur, int size)
{
	int row, col;

	if (!cur)
		return (1);
	else
	{
		row = 0;
		while (row < size )
		{
			col = 0;
			while (col < size )
			{
				// copy = dup_board_test(board, size);
				if (ft_fill(cur, board, row, col, size))
				{
					// ft_print(board);
					// printf("\n");
					if (ft_backtracking(board, cur->next, size))
						return (1);
					else
					{
//						printf("%d, %d\n", row, col);
						ft_fill_remove(cur, board, row, col);
						// ft_print(board);
						// printf("\n");
					}	
				}
				col++;
			}
			row++;
		}
		return (0);
	}
}