/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijhuang <yijhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 23:46:50 by yijhuang          #+#    #+#             */
/*   Updated: 2019/03/03 10:22:19 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct	f_list
{
	int				x[5];
	int				y[5];
	char			sym;
	struct	f_list	*next;
}				t_flist;

t_flist *new_fnode(char **v, char sym);
void	ft_format_board(char **board, int size);
char	**ft_create_board(int size);
void	ft_print_list(t_flist **fl);
int		check_count(char **p);
int		check_relate(int *x, int *y);
int		relate_two(int x1, int y1, int x2, int y2);
t_flist *ft_read_piece(char *filename);
t_flist *append_fnode(t_flist *head, t_flist *node);
void	ft_print(char **res);
void	free_flist(t_flist *head);
int		validate_node(t_flist *node);
void	ft_get_xy(char **p, int *x, int *y);
int		ft_check_point(char **tet, int *ycnt, int *xcnt);
t_flist	*ft_get_list(t_flist *head, char buf[], char sym);
int		ft_fill(t_flist *cur, char **board, int yrow, int xcol, int size);
int		ft_fill_chk(t_flist *cur, char **board, int yrow, int xcol, int size);
void	ft_fill_put(t_flist *cur, char **board, int yrow, int xcol);
void	ft_fill_remove(t_flist *cur, char **board, int yrow, int xcol);
int		ft_backtracking(char **board, t_flist *cur, int size);
char	**ft_to_piece(char buf[]);
t_flist	*read_file_piece(char *fname);
void	free_list(t_flist *list);
void	free_two_char(char **b);
int		ft_get_list_length(t_flist *list);
void	ft_usage(void);

void	ft_get_xy_helper(char **p, int *x, int *y, int	co_x, int co_y);

void	ft_open_error(void);
void	ft_byte_error(void);
void	ft_piece_num_error(void);
void	ft_error(void);
#endif
