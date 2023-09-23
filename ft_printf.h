#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
#	include <stdio.h>


typedef struct s1_list {
	va_list	*args;
	char	*str;
	char	*substr;
	char	prefix;
	int		printed;
	int		arg_count;
	int		dot_flag;
	int		min_flag;
	int		zero_flag;
	int		hash_flag;
	size_t		width;

} t1_list;

int		ft_printf(char *format, ...);
void 	ft_init(t1_list *datalist);
void	ft_subprint(t1_list *datalist);
void	ft_blockprint(t1_list *datalist);
void	ft_zeros(t1_list *datalist);
void	ft_sprint(t1_list *datalist);
void	ft_hprefix(t1_list *datalist);
void	ft_flags(t1_list *datalist);
void	ft_conversion(t1_list *datalist);
char	*ft_itoa_s(int n , t1_list *datalist);
void	ft_conv_p(t1_list *datalist);
void	ft_conv_x(t1_list *datalist);
void	f_detector(t1_list *datalist);
int		ft_digitcount(int c);
int		ft_hexdigits(int dec);
void	ft_strupper(char *str);


#endif
