#include "ft_printf.h"

static void	ft_strupper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

static int	ft_hexdigits(long int dec)
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

static void	ft_conv_x(t1_list *datalist)
{
	const char	*hex_digits = "0123456789abcdef";
	long int	nb;
	int			i;

	nb = va_arg(*datalist->args, long int);
	i = ft_hexdigits(nb);
	datalist->substr = (char *)malloc((i + 1) * sizeof(char));
	datalist->substr[i] = '\0';
	if (nb == 0)
		datalist->substr[0] = '0';
	while (nb > 0)
	{
		i--;
		datalist->substr[i] = hex_digits[nb % 16];
		nb /= 16;
	}
	if (*datalist->str == 'X')
	{
		ft_strupper(datalist->substr);
		datalist->hash_flag ++;
	}
	datalist->hash_flag += 2;
}

static void	ft_conv_p(t1_list *datalist)
{
	const char	*hex_digits = "0123456789abcdef";
	unsigned long int			nb;
	int			i;

	nb = (unsigned long int)va_arg(*datalist->args, void *);
	if (nb != 0)
		i = ft_hexdigits(nb) + 2;
	else
		i = 6;
	datalist->substr = (char *)malloc(i  * sizeof(char));
	datalist->substr[i] = '\0';
	datalist->substr[0] = '0';
	datalist->substr[1] = 'x';
	if (nb == 0)
		ft_strlcpy(datalist->substr, "(nil)", 6);
	while (nb > 0)
	{
		i--;
		datalist->substr[i] = hex_digits[nb % 16];
		nb /= 16;
	}
}

static char	*ft_conv_c(t1_list *datalist)
{
	char *str;
	int		nbr;
	
	nbr = va_arg(*datalist->args, int);
	if (!nbr)
	{
		datalist->printed++;
		if (datalist->width > 0)
			datalist->width--;
	}
	str = (char *)malloc(sizeof (char) * 2);
	str[0] = nbr;
	str[1] = '\0';
	return (str);
}
static char	*ft_conv_s(t1_list *datalist)
{
	char *str;

	str = va_arg(*datalist->args, char *);
	if (!str)
		return ("(null)");
	return (str);

}

static void	ft_precision(t1_list *datalist)
{
	char	*str;
	char	*tmp;
	int		i;

	if (*datalist->str == 'd' || *datalist->str == 'i' || *datalist->str == 'x' || *datalist->str == 'X' || *datalist->str == 'u')
	{
		if (datalist->precision > ft_strlen(datalist->substr))
		{
			str = (char *)malloc(sizeof (char) * (datalist->precision + 1));
			ft_memset(str, '0', datalist->precision - ft_strlen(datalist->substr));
			ft_strlcat(str, datalist->substr, sizeof (char) * (datalist->precision + 1));
			free(datalist->substr);
			datalist->substr = str;
		}
		else if (datalist->precision == 0 && datalist->dot_flag && *datalist->substr == '0')
			datalist->substr = "\0";
	}
	else if(*datalist->str == 's' && datalist->precision < ft_strlen(datalist->substr) && datalist->dot_flag)
	{
		if (datalist->substr == "(null)")
			datalist->precision = 0;
		str = (char *)malloc(sizeof (char) * (datalist->precision + 1));
		ft_strlcpy(str, datalist->substr, sizeof (char) * (datalist->precision + 1));
		datalist->substr = str;
	}
}

int		ft_conversion(t1_list *datalist)
{
	if (*datalist->str == 'c')
		datalist->substr = ft_conv_c(datalist);
	else if (*datalist->str == 's')
		datalist->substr = ft_conv_s(datalist);
	else if (*datalist->str == 'd' || *datalist->str == 'i')
		datalist->substr = ft_itoa_s(va_arg(*datalist->args, int), datalist);
	else if (*datalist->str == 'u')
		datalist->substr = ft_itoa(va_arg(*datalist->args, long int));
	else if (*datalist->str == 'x' || *datalist->str == 'X')
		ft_conv_x(datalist);
	else if (*datalist->str == 'p')
		ft_conv_p(datalist);
	else
	{
		write(1, "%%", 1);
		return (0);
	}
	if (*datalist->str != 'd' && *datalist->str != 'i' && *datalist->str != 'p')
		datalist->prefix = '\0';
	if (*datalist->str != 'x' && *datalist->str != 'X')
		datalist->hash_flag = 0;
	if (*datalist->str == 'c' || *datalist->str == 's')
		datalist->zero_flag = 0;
	ft_precision(datalist);
	return (1);
}


