/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:12:59 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/25 14:13:03 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_conv_x(t_list1 *dlst)
{
	const char	*hex_digits = "0123456789abcdef";
	long int	nb;
	int			i;

	nb = va_arg(*dlst->args, long int);
	i = ft_hexdigits(nb);
	dlst->substr = (char *)malloc((i + 1) * sizeof(char));
	dlst->substr[i] = '\0';
	if (nb == 0)
		dlst->substr[0] = '0';
	while (nb > 0)
	{
		i--;
		dlst->substr[i] = hex_digits[nb % 16];
		nb /= 16;
	}
	if (*dlst->str == 'X')
	{
		ft_strupper(dlst->substr);
		dlst->hash_flag ++;
	}
	dlst->hash_flag += 2;
}

void	ft_conv_p(t_list1 *dlst)
{
	const char			*hex_digits = "0123456789abcdef";
	unsigned long int	nb;
	int					i;

	nb = (unsigned long int)va_arg(*dlst->args, void *);
	if (nb != 0)
		i = ft_hexdigits(nb) + 2;
	else
		i = 5;
	dlst->substr = (char *)malloc((i + 1) * sizeof(char));
	dlst->substr[i] = '\0';
	dlst->substr[0] = '0';
	dlst->substr[1] = 'x';
	if (nb == 0)
		ft_strlcpy(dlst->substr, "(nil)", 6);
	while (nb > 0)
	{
		i--;
		dlst->substr[i] = hex_digits[nb % 16];
		nb /= 16;
	}
}

char	*ft_conv_c(t_list1 *dlst)
{
	char	*str;
	int		nbr;

	nbr = va_arg(*dlst->args, int);
	if (!nbr)
	{
		dlst->printed++;
		if (dlst->width > 0)
			dlst->width--;
	}
	str = (char *)malloc(sizeof (char) * 2);
	if (!str)
		return (NULL);
	str[0] = nbr;
	str[1] = '\0';
	return (str);
}

char	*ft_conv_s(t_list1 *dlst)
{
	char	*str;
	char	*ptr;

	str = va_arg(*dlst->args, char *);
	if (!str)
	{
		ptr = (char *)malloc(sizeof(char) * 7);
		ft_strlcpy(ptr, "(null)", 7);
	}
	else
	{
		ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
		ft_strlcpy(ptr, str, ft_strlen(str) + 1);
	}
	return (ptr);
}
