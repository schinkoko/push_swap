/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:38:39 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/06/13 15:08:32 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

# ifndef DEC_BASE
#  define DEC_BASE 10
# endif

# ifndef HEX_BASE
#  define HEX_BASE 16
# endif

# ifndef DEC
#  define DEC "0123456789"
# endif

# ifndef HEX_LOWER
#  define HEX_LOWER "0123456789abcdef"
# endif

# ifndef HEX_UPPER
#  define HEX_UPPER "0123456789ABCDEF"
# endif

# ifndef PRINTF_ERROR_CODE
#  define PRINTF_ERROR_CODE -1
# endif

int	ft_printf(int fd, const char *str, ...);

// converters and handler
int	print_str(int fd, const char *str);
int	print_char(int fd, char c);
int	print_int(int fd, long n);
int	print_ubase(int fd, uintmax_t n, uintmax_t base, const char *alphabet);
int	print_ptr(int fd, void *n);
int	spec_handler(int fd, va_list *lst, const char **str);

#endif