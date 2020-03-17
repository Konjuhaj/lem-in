/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncount_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 07:58:24 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/05 07:59:06 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ncount_base(long long n, int base)
{
	int		i;
	long	nb;

	nb = n;
	i = 0;
	if (nb <= 0)
	{
		i++;
	}
	while (nb > 0 || nb < 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}
