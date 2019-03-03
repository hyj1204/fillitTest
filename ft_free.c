#include "fillit.h"

void    free_two_char(char **b)
{
    int i;

    i = -1;
    if (b && *b)
    {
        while (b[++i])
            free(b[i]);
    }
    free(b);
}

void    free_list(t_flist *list)
{
    t_flist *tmp;
    if (list)
    {
        
        while (list)
        {
            tmp = list;
            free(tmp);
            list = list->next;  
        }
    }
}