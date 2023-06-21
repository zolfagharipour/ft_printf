#include "ft_printf.h"

static int		ft_nlen(int n)
{
	int		i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}


char	*ft_itoa(int n)
{
	char	*nbr;
	int		i;

	if (n == -2147483648)
		return("-2147483648");
	i = ft_nlen(n) - 1;
	nbr = (char *)malloc(sizeof(char) * (ft_nlen(n) + 1));
	if (!nbr)
		return (0);
	if (n < 0)
	{
		nbr[0] = '-';
		n *= -1;
	}
	nbr[i] = '\0';
	while (n > 0)
	{
		nbr[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	return (nbr);
}

size_t  ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}


int		ft_conversion(t_list *datalist)	//ERROR handling should be added
{
	char	*temp_str;
	if (datalist->str[1] == 'c')
	{
		datalist->substr = (char *)malloc(2 * sizeof(char));
		datalist->substr[0] = va_arg(*datalist->args, int);
		datalist->substr[1] = '\0';
	}
	if (datalist->str[1] == 's')
	{
		datalist->substr = va_arg(*datalist->args, char *);
		//(char *)malloc(ft_strlen(va_arg(*datalist->args, char *))  * sizeof(char));
	}

	datalist->str += 2;
	printf("substr: %s\n", datalist->substr);
}


