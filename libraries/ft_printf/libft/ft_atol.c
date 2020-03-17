/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:32:52 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/08 13:34:50 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long	num;
	long	sign;

	num = 0;
	sign = 1;
	while (*str == '\t' || *str == '\v' || *str == '\r' || *str == '\n'
		|| *str == '\f' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*str++ - '0');
	return (num * sign);
}
