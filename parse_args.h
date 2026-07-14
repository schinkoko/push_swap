/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 21:59:11 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/06/30 15:08:52 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ARGS_H
# define PARSE_ARGS_H

# include "push_swap.h"

# define NO_DIFF 0
# define SPACE_DELIMETER ' '

# define DISORDER_SIMPLE 0.2
# define DISORDER_MEDIUM 0.5

# define SIMPLE_STRATEGY "Simple / O(n²)"
# define MEDIUM_STRATEGY "Medium / O(n√n)"
# define COMPLEX_STRATEGY "O(n log n)"

# define SIMPLE_FLAG "--simple"
# define MEDIUM_FLAG "--medium"
# define COMPLEX_FLAG "--complex"
# define ADAPTIVE_FLAG "--adaptive"
# define BENCH_FLAG "--bench"

# define ERROR_MESSAGE "Error"

size_t	ft_len(char **arr);
long	ft_atol(const char *str);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
void	set_settings(char **argv, t_stack *algo);
int		parse_args(int argc, char **argv);

#endif
