#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*rev_print(char *s)
{
	int	len = strlen(s);

	while (len >= 0)
	{
		write(1, &s[len--], 1);
	}
	return (s);
}

int	main(void)
{
	rev_print("testing string");
	printf("\n");
	return (0);
}