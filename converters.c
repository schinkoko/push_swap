/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 20:27:57 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/06/13 13:48:47 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(int fd, const char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	while (*str)
	{
		if (write(fd, str++, 1) < 0)
			return (PRINTF_ERROR_CODE);
		count++;
	}
	return (count);
}

int	print_char(int fd, char c)
{
	return (write(fd, &c, 1));
}

int	print_int(int fd, long n)
{
	int		res;
	int		sign;

	sign = 0;
	if (n < 0)
	{
		if (print_char(fd, '-') < 0)
			return (PRINTF_ERROR_CODE);
		n = -n;
		sign = 1;
	}
	res = print_ubase(fd, n, DEC_BASE, DEC);
	if (res < 0)
		return (PRINTF_ERROR_CODE);
	return (res + sign);
}

int	print_ubase(int fd, uintmax_t n, uintmax_t base, const char *alphabet)
{
	int	count;
	int	res;

	count = 0;
	if (n >= base)
	{
		res = print_ubase(fd, n / base, base, alphabet);
		if (res < 0)
			return (PRINTF_ERROR_CODE);
		count += res;
	}
	if (print_char(fd, alphabet[n % base]) < 0)
		return (PRINTF_ERROR_CODE);
	return (count + 1);
}

int	print_ptr(int fd, void *ptr)
{
	int	res;

	if (!ptr)
		return (print_str(fd, "(nil)"));
	if (print_str(fd, "0x") < 0)
		return (PRINTF_ERROR_CODE);
	res = print_ubase(fd, (uintptr_t)ptr, HEX_BASE, HEX_LOWER);
	if (res < 0)
		return (PRINTF_ERROR_CODE);
	return (res + 2);
}
