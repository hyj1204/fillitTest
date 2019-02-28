#include "fillit.h"

void	ft_usage(void)
{
	write(1, "usage: ./fillit <FILE>\n", 23);
	exit(0);
}

void    ft_open_error(void)
{
    write(1, "open file failed\n", 17);
	exit(0);
}

void    ft_byte_error(void)
{
    write(1, "read should return 20 but not this\n", 35);
    exit(0);
}

void    ft_piece_num_error(void)
{
    write(1, "num of hash in piece is not correct\n",36);
    exit(0);
}

void    ft_piece_relate_error(void)
{
    write(1, "hash in the piece is not related\n",32);
    exit(0);
}