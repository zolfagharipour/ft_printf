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
	int		width;

} t1_list;

int		ft_printf(char *format, ...) __attribute__ ((format (printf, 1, 2)));
	void 	ft_init(t1_list *datalist);
	//void	ft_percentage_count(t1_list *datalist);
int		ft_blockprint(t1_list *datalist);		//iterate through str and print out characters. if we find %, read the conversion and print matching argument from args using other fuctions 
	int		ft_backslash (t1_list datalist);
int		ft_format(t1_list *datalist);	//call flag first then it calls conversion. checks for errors and moves the pointer.
int		ft_flags(t1_list *datalist);		//read the flags ( +check if its a valid flag-combination) and modifies the t1_list. 
int		ft_conversion(t1_list *datalist);	//switch system. modifies the substr
	int		ft_base_convert(t1_list datalist);		//conversion for the hexadecimal
void	ft_error(int err);
void		ft_subprint(t1_list *datalist);		//using substr and considering all the (just)flags print substr.
	int		ft_cal_width (t1_list datalist);
char	*ft_itoa_s(int n , t1_list *datalist);
//ft_putstr_fd (char *str, int fd);


#endif