/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 20:33:43 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/06/13 15:10:27 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_pow(int precision)
{
	long	exp;

	exp = 1;
	while (precision--)
		exp *= DEC_BASE;
	return (exp);
}

static int	_print_float(long whole, long factor, long frac)
{
	int		tmp;
	int		written;
	long	div;

	written = 0;
	tmp = print_int(whole);
	if (tmp < 0)
		return (ERROR);
	written += tmp;
	if (print_char('.') < 0)
		return (ERROR);
	++written;
	div = factor / 10;
	while (div > 1 && frac < div)
	{
		if (print_char('0') < 0)
			return (ERROR);
		div /= 10;
		++written;
	}
	tmp = print_int(frac);
	if (tmp < 0)
		return (ERROR);
	return (written + tmp);
}

static long	handle_frac(double f, long factor, long *whole)
{
	long	frac;

	frac = (long)((f - *whole) * factor + 0.5);
	if (frac >= factor)
	{
		++(*whole);
		frac = 0;
	}
	return (frac);
}

int	print_float(double f, int precision)
{
	int		tmp;
	int		written;
	long	whole;
	long	frac;

	written = 0;
	if (f < 0)
	{
		if (print_char('-') < 0)
			return (ERROR);
		f = -f;
		++written;
	}
	whole = (long)f;
	frac = handle_frac(f, ft_pow(precision), &whole);
	tmp = _print_float(whole, ft_pow(precision), frac);
	if (tmp < 0)
		return (ERROR);
	return (written + tmp);
}
