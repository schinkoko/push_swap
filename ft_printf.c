/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:50:48 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/06/20 14:36:17 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_precision(const char **str)
{
	if (*(*str)++ == '.')
		return (*(*str)++ - '0');
	return (DEFAULT_PRECISION);
}

int	spec_handler(va_list *lst, const char **str)
{
	char	c;

	c = *(++(*str));
	if (c == 'z')
		c = *(++(*str));
	if (c == 'c')
		return (print_char((char)va_arg(*lst, int)));
	else if (c == 's')
		return (print_str(va_arg(*lst, char *)));
	else if (c == 'p')
		return (print_ptr(va_arg(*lst, void *)));
	else if (c == 'd' || c == 'i')
		return (print_int(va_arg(*lst, int)));
	else if (c == 'f' || c == '.')
		return (print_float(va_arg(*lst, double), get_precision(str)));
	else if (c == 'u')
		return (print_ubase(va_arg(*lst, uintmax_t), DEC_BASE, DEC));
	else if (c == 'x')
		return (print_ubase(va_arg(*lst, uintmax_t), HEX_BASE, HEX_LOWER));
	else if (c == 'X')
		return (print_ubase(va_arg(*lst, uintmax_t), HEX_BASE, HEX_UPPER));
	return (print_char(c));
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		size;
	int		bytes;

	size = 0;
	va_start(lst, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
			bytes = spec_handler(&lst, &str);
		else
			bytes = write(1, str, 1);
		if (bytes < 0)
			return (va_end(lst), ERROR);
		size += bytes;
		++str;
	}
	va_end(lst);
	return (size);
}

// int	main(void) {
// 	ft_printf("This is a string %.6f", 125.00054);
// }