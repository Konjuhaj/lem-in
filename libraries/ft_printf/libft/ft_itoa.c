/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:54:06 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/11 14:43:02 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long long nb)
{
	int		i;
	char	*result;

	i = ncount(nb);
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	result[i--] = '\0';
	if (nb == 0)
	{
		result[0] = 48;
		return (result);
	}
	if (nb < 0)
	{
		nb *= -1;
		result[0] = '-';
	}
	while (nb > 0)
	{
		result[i--] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (result);
}
