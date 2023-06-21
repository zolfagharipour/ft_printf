#include <stdio.h>

int	main ()
{
	float	i = 0;
	int		counter = 0;

	while (i < 0.000001)
	{
		printf("%d --> %10f$\n", counter, i);
		i += 0.0000001;
		counter++;
	}
	return (0);
}