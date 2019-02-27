#include "fillit.h"

t_flist     *ft_read_piece(char *av)
{
    int byte;
    int fd;
    char    buf[22];
    char    *piece;
    t_flist *t;

    if ((fd = open(av, O_RDONLY)) < 0)
    {
        printf("open file fail\n");
        exit(1);
    }
    while ((byte = read(fd, buf, 21)) != -1)
    {
        buf[byte] = '\0';
        if (byte != 21 || buf[byte - 1] != '\n')
        {
            printf("error\n");
            exit(1);
        }
        t = ft_create_list(buf, 21);
    }
}

char    **get_piece(char buf[], int size)
{
    char    **piece;
    int i, j, k;

    i = -1;
    k = 0;
    piece = ft_create_board(4);
    while (piece[++i])
    {
        j = -1;
        while (++j < 4)
        {
            piece[i][j] = buf[k];
        }
        piece[i][j] = '\0';
    }
    return (piece);
}

// t_flist *ft_create_list(char buf[], int size)
// {
//     char    **piece;
//     int i, j, k;

//     i = -1;
//     k = 0;
//     piece = ft_create_board(4);
//     while (piece[++i])
//     {
//         j = -1;
//         while (++j < 4)
//         {
//             piece[i][j] = buf[k];
//         }
//         piece[i][j] = '\0';
//     }
// }