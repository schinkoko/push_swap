/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:38:39 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/06/20 14:39:21 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

# define DEC_BASE 10
# define HEX_BASE 16

# define DEC "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

# define DEFAULT_PRECISION 6

# define ERROR -1

int	print_str(const char *str);
int	print_char(char c);
int	print_int(long n);
int	print_ubase(uintmax_t n, uintmax_t base, const char *alphabet);
int	print_ptr(void *n);
int	spec_handler(va_list *lst, const char **str);
int	ft_printf(const char *str, ...);
int	print_float(double f, int precision);

#endif