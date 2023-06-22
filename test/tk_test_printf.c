#include <stdio.h>
#include <stdarg.h>

	
typedef unsigned char t_byte;

int	main(void)
{
	char	test_c;
	char	*test_s;
	void	*test_p;
	
	int		test_d;
	int		test_i;

	
	unsigned int	test_u;
	
	unsigned int	test_x;
	unsigned int	test_X;
	//-------------------------------
	t_byte	*ptr_byte;
	int	byte1;
	int	byte2;
	int	byte3;
	int	byte4;
	int	byte5;
	int	byte6;
	int	byte7;
	int	byte8;
	int	msb1;
	int	lsb1;
	int	msb2;
	int	lsb2;
	
	byte1 = (t_byte *)&(ptr_bytetest_p);
	byte2 = (t_byte *)&(test_p + 1);
	
	printf("address void * test_p: %p\n", test_p);
	
	msb1 = (byte1 & 0b11110000) >> 4;
	lsb1 = (byte1 & 0b00001111);
	msb2 = (byte2 & 0b11110000) >> 4;
	lsb2 = (byte2 & 0b00001111);

	printf("ptr_byte: %d\n", *ptr_byte);
	printf("msb1: %d\n", msb1);
	printf("lsb1: %d\n", lsb1);
	printf("msb2: %d\n", lsb2);
	printf("lsb2: %d\n", lsb2);
	
	//-------------------------------

	test_c = 'A';
	test_s = "abc";

	
	test_d = 42;
	test_i = 21;
	
	test_u = 10;
	
	test_x = 255;
	test_X = 124;
	
	printf("test_c: %c\n", test_c);
	printf("test_s: %s\n", test_s);
	printf("test_p: %p\n", test_p);
	
	printf("test_d: %d\n", test_d);
	printf("test_i: %i\n", test_i);
	
	printf("test_u: %u\n", test_u);
	
	printf("test_x: %x\n", test_x);
	printf("test_X: %X\n", test_X);
	
	printf("test_%%: %%\n");
	
	
	
	
	
		
	
	return (0);
}
