#include "ft_printf.h"

static void	ft_hprefix(t1_list *datalist)
{
	if (datalist->hash_flag == 6)
	{
		write(1, "0x", 2);
		datalist->printed += 2;
	}
	else if (datalist->hash_flag == 7)
	{
		write(1, "0X", 2);
		datalist->printed += 2;
	}
}

static void	ft_sprint(t1_list *datalist)
{
	if (datalist->hash_flag > 4 && !datalist->zero_flag)
		ft_hprefix(datalist);
	while (*datalist->substr)
	{
		ft_putchar_fd(*datalist->substr, 1);
		datalist->printed++;
		datalist->substr++;
		if (datalist->width > 0)
			datalist->width--;
	}
}

static void	ft_zeros(t1_list *datalist)
{
	size_t	i;

	i = 0;
	while(i < datalist->width - ft_strlen(datalist->substr) && datalist->width > ft_strlen(datalist->substr))
	{
		if (datalist->zero_flag)
		{
			write(1, "0", 1);
			datalist->printed++;
		}
		else
		{
			write(1, " ", 1);
			datalist->printed++;
		}
		i++;
	}
}


void	ft_subprint(t1_list *datalist)
{
	if (datalist->hash_flag > 4 && datalist->zero_flag)
		ft_hprefix(datalist);
	else if (datalist->hash_flag > 4 && !datalist->zero_flag && datalist->width > 1)
		datalist->width -= 2;
	if (datalist->prefix && datalist->width > 1)
		datalist->width--;
	if(!datalist->min_flag)
	{
		if (datalist->zero_flag && datalist->prefix)
		{
			ft_putchar_fd(datalist->prefix, 1);
			datalist->printed++;
		}
		ft_zeros(datalist);
		if (!datalist->zero_flag && datalist->prefix)
		{
			ft_putchar_fd(datalist->prefix, 1);
			datalist->printed++;
		}
		ft_sprint(datalist);
	}
	else
	{
		if (datalist->prefix)
		{
			ft_putchar_fd(datalist->prefix, 1);
			datalist->printed++;
		}
		ft_sprint(datalist);
		ft_zeros(datalist);
	}
}