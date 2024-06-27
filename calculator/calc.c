#include <stdio.h>
#include <stdlib.h>

void    calc(float n1, char c, float n2)
{
        float   res;

        if (c == '-')
                res = n1 - n2;
        else if (c == '+')
                res = n1 + n2;
        else if (c == '*')
                res = n1 * n2;
        else if (c == '/')
                res = n1 / n2;
        else
                res = (int)n1 % (int)n2;
        printf("%f\n", res);
}

int     main(int ac, char **av)
{
        if (ac == 4 && !av[2][1])
                calc(atof(av[1]), av[2][0], atof(av[3]));
        return (0);
}

//Note: for "*", use double quotes in the cml