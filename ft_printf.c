#include "ft_printf.h"

void ft_init(t1_list *datalist)
{
	datalist->str = 0;
	datalist->substr = 0;
	datalist->arg_count = 0;
	datalist->min_flag = 0;
	datalist->zero_flag = 0;
	datalist->width = 0;
}

int		ft_flags(t1_list *datalist)	//ERROR handling should be added
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

int	ft_blockprint(t1_list *datalist)
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