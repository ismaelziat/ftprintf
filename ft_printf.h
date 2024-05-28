/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziat-hi <iziat-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:29:11 by iziat-hi          #+#    #+#             */
/*   Updated: 2024/05/27 20:40:38 by iziat-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define NUMB "0123456789"

int	cases(char c, va_list vl, long *rlen);
int	ft_printf(const char *str, ...);
int	print_chr(int c, long *rlen);
int	print_str(char *str, long *rlen);
int	print_num(long c, long *rlen);
int	print_hex(unsigned long i, long *rlen, char *base, char format);

#endif