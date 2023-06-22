#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


void ft_init(t_list *datalist)
{
	datalist->str = 0;
	datalist->substr = 0;
	datalist->arg_count = 0;
	datalist->min_flag = 0;
	datalist->zero_flag = 0;
	datalist->width = 0;
}

int		ft_flags(t_list *datalist)	//ERROR handling should be added
{
	int		i;

	i = 0;
	if (datalist->str[1] == '-')
	{
		datalist->min_flag = 1;
		datalist->str += 2;
	}
	else if (datalist->str[1] == '0')
	{
		datalist->zero_flag = 1;
		datalist->str += 2;
	}
	else if (datalist->str[1] == '.')
	{
		datalist->zero_flag = 1;
		datalist->str += 2;
	}
	while (ft_isdigit(*datalist->str))
	{
		datalist->width *= 10;
		datalist->width += *datalist->str - 48;
		datalist->str++;
	}
	return (0);
}

int	ft_blockprint(t_list *datalist)
{
	while (*datalist->str != '\0')
	{
		if (*datalist->str == '%')
		{
			if (datalist->str[1] != '%')
			{
				ft_flags(datalist);		//  do error handling if there was an error
				ft_conversion(datalist);
				//ft_subprint(*datalist);
			}
			else
			{
				write (1,"%%",1);
				datalist->str += 2;
			}
		}
		else
			ft_putchar_fd(*datalist->str++, 1);
		// check for \0 inside of format string...
	}

}

int		ft_printf(char *format, ...)
{
	va_list	args;
	t_list	datalist;

	va_start(args, format);
	ft_init(&datalist);
	datalist.printed = 0;
	datalist.str = format;
	datalist.args = &args;	
	ft_blockprint(&datalist); // do error handling if there was an error
	va_end(args);
	return (0);

}

int	main(void)
{
	ft_printf("result: %x", 2147483647);
}