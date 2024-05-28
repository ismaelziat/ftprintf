/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:52:54 by iziat-hi          #+#    #+#             */
/*   Updated: 2024/05/27 20:39:30 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	print_chr(int c, long *rlen)
{
	write(1, &c, 1);
	(*rlen)++;
	return (*rlen);
}

int	print_str(char *str, long *rlen)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*rlen += 6;
		return (*rlen);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		(*rlen)++;
	}
	return (*rlen);
}

int	print_num(long c, long *rlen)
{
	char	digit;

	if (c < 0)
	{
		write(1, "-", 1);
		(*rlen)++;
		print_num(-c, rlen);
	}
	else if (c >= 10)
	{
		print_num(c / 10, rlen);
		print_num(c % 10, rlen);
	}
	else
	{
		digit = NUMB[c];
		write(1, &digit, 1);
		(*rlen)++;
	}
	return (*rlen);
}

int	nil_ptr(long *rlen)
{
	write(1, "(nil)", 5);
	*rlen += 5;
	return (*rlen);
}

int	print_hex(unsigned long i, long *rlen, char *base, char format)
{
	char	digit;
	int		j;
	
	j = 0;
	if (format == 'p')
	{
		if (i == 0)
			return (nil_ptr(rlen));
		if (j == 0)
			write(1, "0x", 2);
		*rlen += 2;
		j++;
	}
	if (i >= 16)
	{
		print_hex(i / 16, rlen, base, format);
		print_hex(i % 16, rlen, base, format);
	}
	else
	{
		digit = base[i];
		write(1, &digit, 1);
		(*rlen)++;
	}
	return (*rlen);
}
