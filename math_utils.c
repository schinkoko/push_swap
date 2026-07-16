/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 23:43:14 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/16 23:43:16 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int n)
{
	int	low;
	int	high;
	int	mid;

	if (n <= 0)
		return (0);
	low = 1;
	high = n / 2 + 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (mid == n / mid && n % mid == 0)
			return (mid);
		else if (mid < n / mid)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (high);
}
