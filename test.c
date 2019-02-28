# include "fillit.h"

// int main()
// {
//     char    **board;
    
//     board = ft_create_board(4);
//     free_two_char(board);
//     return (0);
// }

t_flist *read_file_piece(char *fname)
{
    t_flist *head;

    head = NULL;
    head = ft_read_piece(fname);
    // if (head)
    //     ft_print_list(&head);
    return (head);
}

int main(int argc, char **argv)
{
    char **board;
    int pcs;
    t_flist *head;
    int reg;
    int size;

    reg = 0;
    size = 0;
    head = read_file_piece(argv[1]);
    // printf("get length\n");
    pcs =  ft_get_list_length(head);
    while (size * size < pcs * 4)
        size++;
    // printf("size is %d\n", size);
    while (reg == 0)
    {
//       printf("size is %d\n", size);
        board = ft_create_board(size);
//        printf("init board\n");
//        ft_print(board);
        // printf("------\n");
        reg = ft_backtracking(board, head, size);
//        printf("reg is %d\n", reg);
        if (reg == 1)
            break;
        // printf("after back track\n");
        free_two_char(board);
        size++;
    }
    free_list(head);
    ft_print(board);
    // free_two_char(board);
    return (0);
}

// int main()
// {
//     char    **p;
//     int i;

//     i = -1;
//     p = ft_create_board(4);
//     int x[5] = {0};
//     int y[5] = {0};
//     p[1][0]='#';
//     p[1][1]='#';
//     p[0][0]='#';
//     p[0][1]='#';

//     ft_get_xy(p,x, y, 4);
//     while (++i <4)
// 		printf("%d, %d\n", x[i], y[i]);
//     return (0);
// }
// int main()
// {
//     char tmp[] = {
//                 '.','#','#','#',
//                 '.','.','#','.',
//                 '.','.','.','.',
//                 '.','.','.','.'};
    
//     // char tmp[] = {
//     //             '.','#','#','#',
//     //             '.','.','#','.',
//     //             '.','.','.','.',
//     //             '.','.','.','.'};
//     t_flist *head;
//     head = NULL;
//     head = ft_get_list(head, tmp, 'A');
//     head = ft_get_list(head, tmp, 'B');
//    printf("---------- \n");
//    ft_print_list(&head);
// //    printf(" --------- \n");

//     return (0);
// }

// int main()
// {
//     char tmp[] = {
//                 '.','#','#','#',
//                 '.','.','#','.',
//                 '.','.','.','.',
//                 '.','.','.','.'};

//     char    **reg;
//     reg = get_piece(tmp);
//     ft_print(reg);
//     printf("\n");

//     return (0);
// }


// int main()
// {
//     char    *fname = "text";
//     int byte;
//     int fd;
//     char    buf1[21];
//     char    buf2[2];
//     char    *piece;
//     char    **p;
//     t_flist *head;
//     t_flist *tmp;
//     int i, j, k;

//     if ((fd = open(fname, O_RDONLY)) < 0)
//     {
//         printf("open file fail\n");
//         exit(1);
//     }
//     while ((byte = read(fd, buf1, 20)) > 0)
//     {
//         buf1[20] = '\0';
// //        printf("byte is %d\n the string is\n%s", byte, buf1);
//         if (byte != 20)
//         {
//             printf("read 20 byte error\n");
//             exit(1);
//         }
//         byte = read(fd, buf2, 1);
//         if (byte != 1 && buf2[byte] != '\n')
//         {
//             printf("read 1 byte error\n");
//             exit(1);
//         }
//         head = ft_create_list(buf);
//     }

    // printf("out\n");
    // i = -1;
    // k = 0;
    // p = ft_create_board(4);
    // while (p[++i])
    // {
    //     j = -1;
    //     while (++j < 4)
    //     {
    //         p[i][j] = buf[k];
    //     }
    //     p[i][j] = '\0';
    // }
    // return (0);
// }

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