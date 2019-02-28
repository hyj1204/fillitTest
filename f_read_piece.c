#include "fillit.h"

t_flist     *ft_read_piece(char *av)
{
    int byte;
    int fd;
    char    buf1[21];
    char    buf2[2];
    t_flist *head;
    int id;

    id = 0;
    head = NULL;
    if ((fd = open(av, O_RDONLY)) < 0)
        ft_open_error();
    while ((byte = read(fd, buf1, 20)) > 0)
    {
        // printf("loop %d\n", id);
        buf1[20] = '\0';
        // printf("byte is %d\n the string is\n%s", byte, buf1);
        if (byte != 20)
            ft_byte_error();
        byte = read(fd, buf2, 1);
        // printf("byte is %d\n", byte);
        buf2[1] = '\0';
        if (byte != 0 && buf2[0] != '\n')
            ft_byte_error();
        buf2[0] = '\0';
        head = ft_get_list(head, buf1, id++ + 65);
    }
    return (head);
}

t_flist *ft_get_list(t_flist *head, char buf[], char sym)
{
    char    **piece;
    t_flist *t;

    piece = ft_to_piece(buf);
    // printf("read\n");
    // ft_print(piece);
    // printf("\n");
    if (!check_count(piece))
        ft_piece_num_error();
    t = new_fnode(piece, sym);
    free_two_char(piece);
 //   printf("\n");
    if (!check_relate(t->x, t->y))
        ft_piece_relate_error();
    head = append_fnode(head, t);
    return (head);
}

char    **ft_to_piece(char buf[])
{
    char    **piece;

    int i = -1;
    int k = 0;
    int j = -1;
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