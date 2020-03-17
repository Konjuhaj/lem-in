/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:29:00 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/11 11:30:23 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long num, int base, int id)
{
	int n;

	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
	}
	if (num >= (long long)base)
	{
		ft_putnbr_base(num / base, base, id);
		n = num % base >= 10 ? num % base + 'a' - 10 : num % base + 48;
	}
	else
		n = num >= 10 ? num + 'a' - 10 : num + 48;
	if (n >= 'a' && id == 2)
		n -= 32;
	ft_putchar(n);
}
