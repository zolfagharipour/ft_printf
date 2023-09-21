#include "ft_printf.h"

void ft_init(t1_list *datalist)
{
	datalist->substr = 0;
	datalist->prefix = 0;
	datalist->arg_count = 0;
	datalist->min_flag = 0;
	datalist->zero_flag = 0;
	datalist->hash_flag = 0;
	datalist->width = 0;
}

int		ft_digitcount(int c)
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

void	f_detector(t1_list *datalist)
{
	if (*datalist->str == '0' && !datalist->min_flag)
		datalist->zero_flag = 1;
	if (*datalist->str == '-')
	{
		datalist->min_flag = 1;
		datalist->zero_flag = 0;
	}
	if (*datalist->str == '.')
	{
		datalist->zero_flag = 1;
		datalist->min_flag = 0;
		datalist->dot_flag ++;
	}
	if (*datalist->str == '#')
		datalist->hash_flag ++;
	if (*datalist->str == ' ' && datalist->prefix != '+')
		datalist->prefix = ' ';
	if (*datalist->str == '+')
		datalist->prefix = '+';
}

int		ft_flags(t1_list *datalist)	//ERROR handling should be added
{
	int		i;

	i = 0;
	while (!ft_isalpha(*datalist->str) && (!ft_isalnum(*datalist->str) || *datalist->str == '0'))
	{
		f_detector(datalist);
		datalist->str ++;
	}
	datalist->width = ft_atoi(datalist->str);
	datalist->str += ft_digitcount(datalist->width);
	return (0);
}

int	ft_blockprint(t1_list *datalist)
{
	while (*datalist->str != '\0')
	{
		ft_init(datalist);
		if (*datalist->str == '%')
		{
			datalist->str++;
			if (*datalist->str != '%')
			{
				ft_flags(datalist);		//  do error handling if there was an error
				ft_conversion(datalist);
				ft_subprint(datalist);
			}
			else
			{
				write (1,"%%",1);
				datalist->str += 1;
			}
		}
		else
		{
			ft_putchar_fd(*datalist->str, 1);
			datalist->str++;
		}
	}
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
	ft_blockprint(&datalist); // do error handling if there was an error
	va_end(args);
	return (0);

}