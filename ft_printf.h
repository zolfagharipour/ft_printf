#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
#	include <stdio.h>

# define FT_INT_MAX 2147483647

typedef struct s_list {
	char	*str;
	char	*substr;
	int		printed;
	va_list	*args;
	int		arg_count;
	int		min_flag;
	int		zero_flag;
	int		width;

} t_list;

int		ft_printf(char *format, ...);
	void 	ft_init(t_list *datalist);
	//void	ft_percentage_count(t_list *datalist);
int		ft_blockprint(t_list *datalist);		//iterate through str and print out characters. if we find %, read the conversion and print matching argument from args using other fuctions 
	int		ft_backslash (t_list datalist);
int		ft_format(t_list *datalist);	//call flag first then it calls conversion. checks for errors and moves the pointer.
int		ft_flags(t_list *datalist);		//read the flags ( +check if its a valid flag-combination) and modifies the t_list. 
int		ft_conversion(t_list *datalist);	//switch system. modifies the substr
	int		ft_base_convert(t_list datalist);		//conversion for the hexadecimal
void	ft_error(int err);
int		ft_subprint(t_list datalist);		//using substr and considering all the (just)flags print substr.
	int		ft_cal_width (t_list datalist);
//ft_putstr_fd (char *str, int fd);


#endif