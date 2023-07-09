#include "ft_printf.h"
//#include <stdint.h>

void addressToString(char* buffer, size_t address) {
  const char* hexChars = "0123456789ABCDEF";
  int i = 0;
  
  // Convert the address to hexadecimal string representation
  while (address != 0) {
    buffer[i++] = hexChars[address & 0xF];
    address >>= 4;
  }
  
  // Add the "0x" prefix
  buffer[i++] = 'x';
  buffer[i++] = '0';
  
  // Reverse the string
  int j = 0;
  while (j < i / 2) {
    char temp = buffer[j];
    buffer[j] = buffer[i - j - 1];
    buffer[i - j - 1] = temp;
    j++;
  }
  
  // Add null terminator
  buffer[i] = '\0';
}

int	main(void)
{
  	size_t num = 42;
	char address[20];
	addressToString(address, (size_t)&num);
    printf("Memory address: %s\n", address);
    return 0;
}