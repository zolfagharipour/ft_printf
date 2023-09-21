#include "ft_printf.h"

static int	ft_nlen(int n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_s(int n , t1_list *datalist)
{
	long int	ncpy;
	char		*nbr;
	int			i;

	ncpy = n;
	i = ft_nlen (ncpy);
	nbr = (char *)malloc(sizeof(char) * (i + 1));
	if (!nbr)
		return (0);
	nbr[i] = '\0';
	if (ncpy < 0)
	{
		datalist->prefix = '-';
		ncpy *= -1;
	}
	if (ncpy == 0)
		nbr[0] = '0';
	while (ncpy > 0)
	{
		i--;
		nbr[i] = (ncpy % 10) + 48;
		ncpy /= 10;
	}
	return (nbr);
}