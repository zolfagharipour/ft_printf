#include "ft_printf.h"

static 	void ft_init(t1_list *datalist)
{
	datalist->substr = 0;
	datalist->prefix = 0;
	datalist->arg_count = 0;
	datalist->dot_flag = 0;
	datalist->min_flag = 0;
	datalist->zero_flag = 0;
	datalist->hash_flag = 0;
	datalist->percent = 0;
	datalist->width = 0;
	datalist->precision = 0;
}

static int		ft_digitcount(int c)
{
	int	i;

	i = 0;
	while (c != 0)
	{
		c /= 10;
		i++;
	}
	return (i);
}

static void	f_detector(t1_list *datalist)
{
	if (*datalist->str == '0' && !datalist->min_flag && !datalist->dot_flag)
		datalist->zero_flag = 1;
	else if (*datalist->str == '-')
	{
		datalist->min_flag = 1;
		datalist->zero_flag = 0;
	}
	else if (*datalist->str == '.')
	{
		datalist->dot_flag ++;
		datalist->zero_flag = 0;
	}
	else if (*datalist->str == '#')
		datalist->hash_flag += 4;
	else if (*datalist->str == ' ' && datalist->prefix != '+')
		datalist->prefix = ' ';
	else if (*datalist->str == '+')
		datalist->prefix = '+';
	else if (*datalist->str == '+')
		datalist->prefix = '+';
	else if (*datalist->str == '%')
		datalist->percent = 1;		
}

static int		ft_flags(t1_list *datalist)
{
	while (!ft_isalpha(*datalist->str) && *datalist->str != '\0' && *datalist->str != '%')
	{
		if (!ft_isalnum(*datalist->str) || *datalist->str == '0')
		{
		f_detector(datalist);
		datalist->str ++;
		}
		else
		{
			if (!datalist->dot_flag)
			{
				datalist->width = ft_atoi(datalist->str);
				datalist->str += ft_digitcount(datalist->width);
			}
			else
			{
				datalist->precision = ft_atoi(datalist->str);
				datalist->str += ft_digitcount(datalist->precision);
			}
		}
	}
	if (*datalist->str == '\0')
		return (0);
	else if (*datalist->str == '%')
		return (2);
	return (1);
}

static int	ft_blockprint(t1_list *datalist)
{
	char	*ptr;
	int		i;

	while (*datalist->str != '\0')
	{
		ft_init(datalist);
		if (*datalist->str == '%')
		{
			datalist->str++;
			if (*datalist->str != '%')
			{
				ptr = datalist->str;
				if (!ft_flags(datalist))
					return (0);
				else if (*datalist->str == '%')
				{
					write (1,"%%",1);
					datalist->printed++;
					datalist->str += 1;
				}
				else
				{
					if (!ft_conversion(datalist))
						datalist->str = ptr;
					else
					{
						datalist->str++;
						ft_subprint(datalist);
					}
				}
			}
			else
			{
				write (1,"%%",1);
				datalist->printed++;
				datalist->str += 1;
			}
		}
		else
		{
			ft_putchar_fd(*datalist->str, 1);
			datalist->printed++;
			datalist->str++;
		}
	}
	return (1);
}

int		ft_printf(char *format, ...)
{
	va_list	args;
	t1_list	datalist;

	va_start(args, format);
	ft_init(&datalist);
	datalist.printed = 0;
	datalist.str = format;
	datalist.args = &args;	
	if (!ft_blockprint(&datalist))
	{
		va_end(args);
		return (-1);
	}
	va_end(args);
	return (datalist.printed);
}
