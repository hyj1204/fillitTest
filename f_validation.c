#include "fillit.h"

static int diff(int x, int y)
{
    return (((x - y) == 1)|| ((y - x) == 1));
}

int     check_relate(int *x, int *y)
{
    int i;
    int j;
    int reg;

    i = -1;
    reg = 0;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
        {
            reg += relate_two(x[i], y[i], x[j], y[j]);
        }
    }
    if (reg == 6 || reg == 8)
        return (1);
    return (0);
}

int     relate_two(int x1, int y1, int x2, int y2)
{
    if (x1 == x2 && diff(y1, y2))
        return (1);
    else if (y1 == y2 && diff(x1, x2))
        return (1);
    return (0);
}