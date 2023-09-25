/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:50:00 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/25 13:50:01 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexdigits(long int dec)
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

static void	ft_precision(t_list1 *dlst)
{
	char	*str;

	if (*dlst->str == 'd' || *dlst->str == 'i' || *dlst->str == 'x'
		|| *dlst->str == 'X' || *dlst->str == 'u')
	{
		if (dlst->precision > ft_strlen(dlst->substr))
		{
			str = (char *)malloc(sizeof (char) * (dlst->precision + 1));
			ft_memset(str, '0', dlst->precision - ft_strlen(dlst->substr));
			ft_strlcat(str, dlst->substr, sizeof(char) * (dlst->precision + 1));
			(free(dlst->substr), dlst->substr = str);
		}
		else if (dlst->precision == 0 && dlst->dot_flag && *dlst->substr == '0')
			dlst->substr = "\0";
	}
	else if (*dlst->str == 's' && dlst->precision < ft_strlen(dlst->substr)
		&& dlst->dot_flag)
	{
		if (ft_strncmp(dlst->substr, "(null)", 7) == 0)
			dlst->precision = 0;
		str = (char *)malloc(sizeof (char) * (dlst->precision + 1));
		ft_strlcpy(str, dlst->substr, sizeof (char) * (dlst->precision + 1));
		(free(dlst->substr), dlst->substr = str);
	}
}

int	ft_conversion(t_list1 *dlst)
{
	if (*dlst->str == 'c')
		dlst->substr = ft_conv_c(dlst);
	else if (*dlst->str == 's')
		dlst->substr = ft_conv_s(dlst);
	else if (*dlst->str == 'd' || *dlst->str == 'i')
		dlst->substr = ft_itoa_s(va_arg(*dlst->args, int), dlst);
	else if (*dlst->str == 'u')
		dlst->substr = ft_itoa(va_arg(*dlst->args, long int));
	else if (*dlst->str == 'x' || *dlst->str == 'X')
		ft_conv_x(dlst);
	else if (*dlst->str == 'p')
		ft_conv_p(dlst);
	else
	{
		write(1, "%%", 1);
		return (0);
	}
	if (*dlst->str != 'd' && *dlst->str != 'i' && *dlst->str != 'p')
		dlst->prefix = '\0';
	if (*dlst->str != 'x' && *dlst->str != 'X')
		dlst->hash_flag = 0;
	if (*dlst->str == 'c' || *dlst->str == 's')
		dlst->zero_flag = 0;
	ft_precision(dlst);
	return (1);
}
