/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:54:06 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/05 07:59:07 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long nb, int base)
{
	int				i;
	int				num;
	char			*result;

	i = ncount_base(nb, base);
	if (nb == -9223372036854775807 - 1)
		i = 20;
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	result[i--] = '\0';
	if (nb == 0)
		result[0] = 48;
	if (nb < 0)
		result[0] = '-';
	while (nb != 0)
	{
		num = nb % base < 0 ? nb % base * -1 : nb % base;
		result[i--] = num >= 10 ? num + 87 : num + 48;
		nb = nb / base;
	}
	return (result);
}
