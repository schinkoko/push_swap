/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:45:58 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/27 22:47:20 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
}

static bool	parse_long_digits(
	const char *str, unsigned long limit, int sign, long *num)
{
	unsigned long	value;
	int				digit;

	value = 0;
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		if (value > (limit - digit) / 10)
			return (false);
		value = value * 10 + digit;
		++str;
	}
	while (ft_isspace(*str))
		++str;
	if (*str != '\0')
		return (false);
	if (sign == -1 && value == (unsigned long)LONG_MAX + 1)
		*num = LONG_MIN;
	else if (sign == -1)
		*num = -(long)value;
	else
		*num = (long)value;
	return (true);
}

bool	ft_atol(const char *str, long *num)
{
	unsigned long	limit;
	int				sign;

	if (!str || !num)
		return (false);
	while (ft_isspace(*str))
		++str;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	if (*str < '0' || *str > '9')
		return (false);
	limit = (unsigned long)LONG_MAX + (sign == -1);
	return (parse_long_digits(str, limit, sign, num));
}

static size_t	int_len(int n)
{
	size_t	len;
	long	nb;

	len = 0;
	if (n == 0)
		return (1);
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		++len;
	}
	while (nb)
	{
		nb /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	nb;
	char	*str;

	len = int_len(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	nb = n;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
