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

int	print_str(const char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	while (*str)
	{
		if (write(1, str++, 1) < 0)
			return (ERROR);
		count++;
	}
	return (count);
}

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_int(long n)
{
	int		res;
	int		sign;

	sign = 0;
	if (n < 0)
	{
		if (print_char('-') < 0)
			return (ERROR);
		n = -n;
		sign = 1;
	}
	res = print_ubase(n, DEC_BASE, DEC);
	if (res < 0)
		return (ERROR);
	return (res + sign);
}

int	print_ubase(uintmax_t n, uintmax_t base, const char *alphabet)
{
	int	count;
	int	res;

	count = 0;
	if (n >= base)
	{
		res = print_ubase(n / base, base, alphabet);
		if (res < 0)
			return (ERROR);
		count += res;
	}
	if (print_char(alphabet[n % base]) < 0)
		return (ERROR);
	return (count + 1);
}

int	print_ptr(void *ptr)
{
	int	res;

	if (!ptr)
		return (print_str("(nil)"));
	if (print_str("0x") < 0)
		return (ERROR);
	res = print_ubase((uintmax_t)(uintptr_t)ptr, HEX_BASE, HEX_LOWER);
	if (res < 0)
		return (ERROR);
	return (res + 2);
}
