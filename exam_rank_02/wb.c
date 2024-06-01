int     ft_strlen(char *s)
{
        char    *start = s;

        while (*s++)
                ;
        return (s - start - 1);
}


/*int     ft_strlen(char *str)
{
        int     len = 0;

        while (*str++)
                len++;
        return (len);
}*/

#include <stdio.h>

int     main()
{
        char *s = "12345";

        printf("Len: %d\n", ft_strlen(s));
        return (0);
}