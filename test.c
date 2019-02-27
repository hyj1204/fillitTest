# include "fillit.h"

int main()
{
    char    *fname = "text";
    int byte;
    int fd;
    char    buf[22];
    char    *piece;
    char    **p;
    int i, j, k;

    if ((fd = open(fname, O_RDONLY)) < 0)
    {
        printf("open file fail\n");
        exit(1);
    }
    while ((byte = read(fd, buf, 21)) != -1)
    {
        buf[byte] = '\0';
        if (byte != 20 && buf[byte - 2] != '\n')
        {
            // printf("byte is %d\n the string is\n%s", byte, buf);
            // printf("buf[byte - 1] is %c\n", buf[byte - 1]);
            // break;
            printf("error\n");
            exit(1);
        }
    }
    printf("out\n");
    i = -1;
    k = 0;
    p = ft_create_board(4);
    while (p[++i])
    {
        j = -1;
        while (++j < 4)
        {
            p[i][j] = buf[k];
        }
        p[i][j] = '\0';
    }
    return (0);
}

//test get_next_line;
// #include "fillit.h"

// int main()
// {
//      char    *fname = "text";
// int fd;
//     int reg;
//     char    *line;
   
//     int p_count;
//     int     i;
  
    
//     line = NULL;
//     reg = 0;
  
//     fd = open(fname, O_RDONLY);
  

//     while (((reg = get_next_line(fd, &line)) != 0) )
// 	{
//         printf("%s", line);
        
//     }
// }


// int main()
// {
//     // char test[4][4] =
//     // {
//     //     {'.', '.', '.', '.'},
//     //     {'#', '#', '#', '.'},
//     //     {'#', '.', '.', '.'},
//     //     {'.', '.', '.', '.'}
//     // };
//     char **p;
//     char **k;
//     char **m;
//     t_flist *tmp;
//     t_flist *head;
//     head = NULL;
//     p = ft_create_board(4);
//     k = ft_create_board(4);
//     m = ft_create_board(4);
//     p[1][0]='#';
//     p[1][1]='#';
//     p[0][0]='#';
//     p[0][1]='#';

//     k[3][0]='#';
//     k[3][1]='#';
//     k[2][2]='#';
//     k[2][3]='#';

//     m[1][2]='#';
//     m[1][1]='#';
//     m[1][0]='#';
//     m[0][0]='#';

//     printf("board:\n");
//     ft_print(p);
//     printf("\n");
//     printf("the piece\n");
//     ft_print(k);
//     printf("\n");
//     printf("the piece\n");
//     ft_print(k);
//     printf("\n");
//     tmp = new_fnode(k, 'A');
//     head = append_fnode_n(head, tmp);

//     tmp = new_fnode(k, 'B');
//     head = append_fnode_n(head, tmp);

//     printf("the list\n");
//     ft_printf_list(&head);
//     printf("\n");
//     ft_backtracking(p, head, 4);
//     printf("after fill\n");
//     ft_print(p);
//     return (0);
// }

//test read_piece;
// int main()
// {
//     char    *fname = "text";
//     t_flist *   t_list;
//     t_list = read_piece(fname);
//     ft_printf_list(&t_list);
//     return (0);
// }


// int main()
// {
//     // char test[4][4] =
//     // {
//     //     {'.', '.', '.', '.'},
//     //     {'#', '#', '#', '.'},
//     //     {'#', '.', '.', '.'},
//     //     {'.', '.', '.', '.'}
//     // };
//     char **p;
//     // char **k;
//     t_flist *fl;
//     p = ft_create_board(4);
//     // k = ft_create_board(4);
//     p[1][0]='#';
//     p[1][1]='#';
//     p[2][1]='#';
//     p[3][1]='#';

//     ft_print(p);
  
//     printf("\n");
//     // printf("append node\n");
//     // fl = new_fnode(p, 'A');
//     // printf("finish new node\n");
//     printf("%d\n",check_count(p));

//     return (0);
// }


// int main()
// {
//     // char test[4][4] =
//     // {
//     //     {'.', '.', '.', '.'},
//     //     {'#', '#', '#', '.'},
//     //     {'#', '.', '.', '.'},
//     //     {'.', '.', '.', '.'}
//     // };
//     char **p;
//     char **k;
//     t_flist *fl;
//     p = ft_create_board(4);
//     k = ft_create_board(4);
//     p[1][0]='#';
//     p[1][1]='#';
//     p[2][1]='#';
//     p[3][1]='#';

//     ft_print(p);
  

//     printf("append node\n");
//     fl = new_fnode(p, 'A');
//     printf("finish new node\n");
//     printf("%d\n",check_relate(fl->x, fl->y));

//     return (0);
// }

// int main()
// {
//     // char test[4][4] =
//     // {
//     //     {'.', '.', '.', '.'},
//     //     {'#', '#', '#', '.'},
//     //     {'#', '.', '.', '.'},
//     //     {'.', '.', '.', '.'}
//     // };
//     char **p;
//     char **k;
//     t_flist **fl;
//     p = ft_create_board(4);
//     k = ft_create_board(4);
//     p[1][0]='#';
//     p[2][0]='#';
//     p[1][1]='#';
//     p[1][2]='#';

//     k[3][0]='#';
//     k[3][1]='#';
//     k[3][2]='#';
//     k[3][3]='#';
//     fl = (t_flist**)malloc(sizeof(t_flist*));
//     *fl = NULL;
//     printf("append node\n");
//     append_fnode(fl, 'A', p);
  
    
//     append_fnode(fl, 'B', k);
//     printf("print list\n");
//     ft_printf_list(fl);

//     return (0);
// }