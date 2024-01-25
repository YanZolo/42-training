#include "ft_printf.h"

int	main(void)
{
	char	*str;
	char	c;
	char	*book;
	float	price;
	int		quantity;

	book = "The Alchimist";
	price = 15.51;
	quantity = 42;
	str = "just do it";
	c = 'T';
	// printf("\n\n\t---------------FT_PRINTF TESTS----------------\n\n");
	// 
	// printf("--SPECIFIER S, POSSIBLE CASES:--\n\n");
	// 
	// printf("\t========-ORIGINAL PRINTF-========\n");
	// printf("0: test %%s\n==>\t|%s|\n\n", str);	
	// printf("1: test %%20s\n==>\t|%20s|\n\n", str);	
	// printf("2: test %%5.2s\n==>\t|%5.2s|\n\n", str);	
	// printf("3: test %%-20.2s\n==>\t|%-20.2s|\n\n", str);	
	// printf("4: test %%.2s\n==>\t|%.2s|\n\n", str);	
	// printf("lenght = %d\n", printf("#: test output lenght\n==>\t|%s|\n", str));	
	// 
	// printf("\n======================END========================\n\n\n");
	
	// ft_printf("\t========-MY FT_PRINTF FUNCTION-========\n\n");
	// ft_printf("0: test %%s\n==>\t|%s|\n\n", str);	
	// ft_printf("1: test %%.2s\n==>\t|%.2s|\n\n", str);	
	// ft_printf("1: test %%20.2s\n==>\t|%20.2s|\n\n", str);	
	ft_printf("clone:    |%-5.2s|\n", str);	
	printf("original: |%-5.2s|\n\n", str);	
	ft_printf("clone:    |%5.2s|\n", str);	
	printf("original: |%5.2s|\n\n", str);	
	ft_printf("clone:    |%.2s|\n", str);	
	printf("original: |%.2s|\n\n", str);	
	
	// ft_printf("lenght = %d\n", ft_printf("#: test output lenght\n==>\t|%s|\n", str));	
	// ft_printf("\n======================END========================\n\n\n");

	return (0);
}