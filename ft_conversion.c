#include "ft_printf.h"

void	ft_strupper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
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

void	ft_conv_x(t1_list *datalist)
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
	if (*datalist->str == 'X')
	{
		ft_strupper(datalist->substr);
		datalist->hash_flag ++;
	}
	datalist->hash_flag += 2;
}

void	ft_conv_p(t1_list *datalist)
{
	const char	*hex_digits = "0123456789abcdef";
	unsigned long int			nb;
	int			i;

	nb = (unsigned long int)va_arg(*datalist->args, void *);
	i = 14;
	datalist->substr = (char *)malloc(i  * sizeof(char));
	datalist->substr[13] = '\0';
	datalist->substr[0] = '0';
	datalist->substr[1] = 'x';
	while (nb > 0)
	{
		i--;
		datalist->substr[i] = hex_digits[nb % 16];
		nb /= 16;
	}
	if (*datalist->str == 'X')
		ft_strupper(datalist->substr);
}

void		ft_conversion(t1_list *datalist)	//ERROR handling should be added
{
	if (*datalist->str == 'c')
		datalist->substr = ft_itoa(va_arg(*datalist->args, int) - 48);
	else if (*datalist->str == 's')
		datalist->substr = va_arg(*datalist->args, char *);
	else if (*datalist->str == 'd' || *datalist->str == 'i')
		datalist->substr = ft_itoa_s(va_arg(*datalist->args, int), datalist);
	else if (*datalist->str == 'u')
		datalist->substr = ft_itoa(va_arg(*datalist->args, long int));
	else if (*datalist->str == 'x' || *datalist->str == 'X')
		ft_conv_x(datalist);
	else if (*datalist->str == 'p')
		ft_conv_p(datalist);
	if (*datalist->str != 'd' && *datalist->str != 'i' && *datalist->str != 'p')
		datalist->prefix = '\0';
	if (*datalist->str != 'x' && *datalist->str != 'X')
		datalist->hash_flag = 0;
	if (*datalist->str == 'c' || *datalist->str == 's')
	{
		datalist->zero_flag = 0;
		datalist->dot_flag ++;
		if (datalist->width > ft_strlen(datalist->substr))
			datalist->width = ft_strlen(datalist->substr);
	}
	datalist->str ++;
}


