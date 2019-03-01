#include "fillit.h"


t_flist     *ft_read_piece(char *av)
{
    int byte1, byte2;
    int fd;
    char    buf1[21];
    char    buf2[2];
    t_flist *head;
    int id;

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
    }
    if (byte1 == 0 && byte2 == -1)
        ft_byte_error();
    return (head);
}