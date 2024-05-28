/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:55:35 by iziat-hi          #+#    #+#             */
/*   Updated: 2024/05/28 11:59:10 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
#define HEX_LOW "0123456789abcdef"
#define HEX_UP "0123456789ABCDEF"

int	cases(char c, va_list vl, long *rlen)
{
	if (c == 'c')
		print_chr(va_arg(vl, int), rlen);
	if (c == 's')
		print_str(va_arg(vl, char *), rlen);
	if (c == 'i' || c == 'd')
		print_num(va_arg(vl, int), rlen);
	if (c == 'u')
		print_num(va_arg(vl, unsigned int), rlen);
	if (c == 'x')
		print_hex(va_arg(vl, unsigned long), rlen, HEX_LOW, 'x');
	if (c == 'p')
		print_hex(va_arg(vl, unsigned long), rlen, HEX_LOW, 'p');
	if (c == 'X')
		print_hex(va_arg(vl, unsigned long), rlen, HEX_UP, 'X');
	if (c == '%')
		return (write (1, "%", 1), (*rlen)++);
	return (*rlen);
}

/*int	ft_printf(const char *str, ...)
{
	va_list	vl;
	long	rlen;
	int		i;

	rlen = 0;
	i = 0;
	va_start(vl, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			cases(str[i], vl, &rlen);
		}
		else
		{
			write(1, &str[i], 1);
			rlen++;
		}
		i++;
	}
	return (va_end(vl), rlen);
}

int main()
{
	int 	rlen1, rlen2;
	char	*ptr = NULL;
	
	rlen1 = ft_printf("Hello char, %c\n", NULL);
	rlen2 = printf("Hello char, %c\n", 0);
	printf("ft_printf returned: %d\n", rlen1);
	printf("printf returned: %d\n", rlen2);

 	rlen1 = ft_printf("Hello string, %s\n", "world");
	rlen2 = printf("Hello string, %s\n", "world");
	printf("ft_printf returned: %d\n", rlen1);
	printf("printf returned: %d\n", rlen2);

	rlen1 = ft_printf("Hello hex, %x\n", 25555);
	rlen2 = printf("Hello hex, %x\n", 25555);
	printf("ft_printf returned: %d\n", rlen1);
	printf("printf returned: %d\n", rlen2);

	rlen1 = ft_printf("Hello ptr, %p\n", ptr);
	rlen2 = printf("Hello ptr, %p\n", ptr);
	printf("ft_printf returned: %d\n", rlen1);
	printf("printf returned: %d\n", rlen2);

	rlen1 = ft_printf("Hello HEX, %X\n", 255);
	rlen2 = printf("Hello HEX, %X\n", 255);
	printf("ft_printf returned: %d\n", rlen1);
	printf("printf returned: %d\n", rlen2);

	rlen1 = ft_printf("Hello dig, %d\n", 777);
	rlen2 = printf("Hello dig, %d\n", 777);
	printf("ft_printf returned: %d\n", rlen1);
	printf("printf returned: %d\n", rlen2);

	rlen1 = ft_printf("Hello int, %i\n", 777);
	rlen2 = printf("Hello int, %i\n", 777);
	printf("ft_printf returned: %d\n", rlen1);
	printf("printf returned: %d\n", rlen2);

	rlen1 = ft_printf("Hello uns, %u\n", 777);
	rlen2 = printf("Hello uns, %u\n", 777);
	printf("ft_printf returned: %d\n", rlen1);
	printf("printf returned: %d\n", rlen2);

	rlen1 = ft_printf("Hello percent, %%\n");
	rlen2 = printf("Hello percent, %%\n");
	printf("ft_printf returned: %d\n", rlen1);
	printf("printf returned: %d\n", rlen2); 
	return 0;
}*/