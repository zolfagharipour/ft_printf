#include "ft_printf.h"

void	ft_hprefix(t1_list *datalist)
{
	if (datalist->hash_flag == 2)
		write(1, "0x", 2);
	else
		write(1, "0X", 2);
}

void	ft_sprint(t1_list *datalist)
{
	if (datalist->hash_flag > 1 && !datalist->zero_flag)
		ft_hprefix(datalist);
	if (datalist->dot_flag == 2)
	{
		while (*datalist->substr && datalist->width > 0)
		{
			ft_putchar_fd(*datalist->substr, 1);
			datalist->width--;
			datalist->substr++;
		}
	}
	else
		while (*datalist->substr)
		{
			ft_putchar_fd(*datalist->substr, 1);
			datalist->substr++;
		}
}

void	ft_zeros(t1_list *datalist)
{
	int	i;

	i = 0;
	while(i < datalist->width - ft_strlen(datalist->substr) && datalist->width > ft_strlen(datalist->substr))
	{
		if (datalist->zero_flag)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
	}
}


void	ft_subprint(t1_list *datalist)
{
	if (datalist->hash_flag > 1 && datalist->zero_flag)
		ft_hprefix(datalist);
	else if (datalist->hash_flag > 1 && !datalist->zero_flag && datalist->width > 2)
		datalist->width -= 2;
	if (datalist->prefix)
	{
		ft_putchar_fd(datalist->prefix, 1);
		if (datalist->prefix != '-')
			datalist->width--;
	}
	if(!datalist->min_flag)
	{
		ft_zeros(datalist);
		ft_sprint(datalist);
	}
	else
	{
		datalist->width -= ft_strlen(datalist->substr);
		ft_sprint(datalist);
		ft_zeros(datalist);
	}
}