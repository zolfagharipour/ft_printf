#include "ft_printf.h"

static int		ft_nlen(long int n)
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


char	*ft_itoa(long int n)
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







int	ft_strupper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

int	ft_conv_u(t_list *datalist)
{
	long int	nb;

	//if (nb > FT_INT_MAX)
	if (nb > 2147483647)
	{
		printf("Number too large. Add error handling...");//ERROR handling should be added
		return (1);
	}
	nb = va_arg(*datalist->args, int);
	if (nb < 0)
		nb = 4294967295 + nb;
	datalist->substr = ft_itoa(nb);
	return (0);
}


int	ft_hexdigits(int dec)
{
	int		counter;

	counter = 0;
	while (dec > 0)
	{
		dec /= 16;
		counter++;
	}
	if (counter != 0)
		return (counter);
	else
		return (1);

}

int	ft_conv_x(t_list *datalist)
{
	const char	*hex_digits = "0123456789abcdef";
	int			nb;
	int			i;

	nb = va_arg(*datalist->args, int);
	i = ft_hexdigits(nb);
	datalist->substr = (char *)malloc((i + 1) * sizeof(char));
	datalist->substr[i] = '\0';
	while (nb > 0)
	{
		i--;
		datalist->substr[i] = hex_digits[nb % 16];
		nb /= 16;
	}
	if (datalist->str[1] == 'X')
		ft_strupper(datalist->substr);
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
	else if (datalist->str[1] == 's')
		datalist->substr = va_arg(*datalist->args, char *);
	else if (datalist->str[1] == 'd' || datalist->str[1] == 'i')
		datalist->substr = ft_itoa(va_arg(*datalist->args, int));
	else if (datalist->str[1] == 'u')
		ft_conv_u(datalist);
	else if (datalist->str[1] == 'x' || datalist->str[1] == 'X')
		ft_conv_x(datalist);

	datalist->str += 2;
	printf("<substr> %s\n", datalist->substr);
}


