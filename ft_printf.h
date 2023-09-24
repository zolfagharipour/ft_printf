#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"
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
	int		percent;
	size_t		width;
	size_t		precision;

} t1_list;


int		ft_printf(char *format, ...);
void	ft_subprint(t1_list *datalist);
int		ft_conversion(t1_list *datalist);
char	*ft_itoa_s(int n , t1_list *datalist);



#endif
