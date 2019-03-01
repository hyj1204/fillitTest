#include "fillit.h"

void	ft_usage(void)
{
	write(1, "usage: ./fillit <FILE>\n", 23);
	exit(0);
}

void    ft_open_error(void)
{
    write(1, "error\n", 6);
	exit(0);
}

void    ft_byte_error(void)
{
    write(1, "error\n", 6);
    exit(0);
}

void    ft_piece_num_error(void)
{
    write(1, "error\n", 6);
    exit(0);
}

void    ft_piece_relate_error(void)
{
    write(1, "error\n", 6);
    exit(0);
}
