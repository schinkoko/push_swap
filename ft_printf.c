/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:50:48 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/06/13 15:07:35 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	spec_handler(int fd, va_list *lst, const char **str)
{
	char	c;

	c = *(++(*str));
	if (c == 'c')
		return (print_char(fd, (char)va_arg(*lst, int)));
	else if (c == 's')
		return (print_str(fd, va_arg(*lst, char *)));
	else if (c == 'p')
		return (print_ptr(fd, va_arg(*lst, void *)));
	else if (c == 'd' || c == 'i')
		return (print_int(fd, va_arg(*lst, int)));
	else if (c == 'u')
		return (print_ubase(fd, va_arg(*lst, unsigned int), DEC_BASE, DEC));
	else if (c == 'x')
		return (
			print_ubase(fd, va_arg(*lst, unsigned int), HEX_BASE, HEX_LOWER)
		);
	else if (c == 'X')
		return (
			print_ubase(fd, va_arg(*lst, unsigned int), HEX_BASE, HEX_UPPER)
		);
	return (print_char(fd, c));
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	lst;
	int		size;
	int		bytes;

	size = 0;
	va_start(lst, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
			bytes = spec_handler(fd, &lst, &str);
		else
			bytes = write(fd, str, 1);
		if (bytes < 0)
			return (va_end(lst), PRINTF_ERROR_CODE);
		size += bytes;
		++str;
	}
	va_end(lst);
	return (size);
}
