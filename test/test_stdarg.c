#include "ft_printf.h"

void	arg_test(va_list args)
{
	printf("%d\n", va_arg(args, int));
}

void	ft_test(int nb, ...)
{
	int			i = 0;
	int			sum = 0;
	va_list		args;
	va_list		args1;

	va_start (args1, nb);
	va_copy (args, args1);
	va_end (args1);
	

	arg_test(args);
	// while (i < nb)
	// {
	// 	sum += (int)va_arg(args, void);
	// 	i++;
	// }
	va_end (args);
	//printf ("%d\n", sum);
}


int main()
{
	ft_test(5, 1, 2, 3, 4, 5);
	return(0);
}