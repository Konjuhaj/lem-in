/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:53:35 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/05 12:02:14 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** add 5 to the number left of the precision to round up
*/

double		round_up(double num, int prec)
{
	double	i;
	int		n;

	n = prec;
	i = 5.0;
	while (n--)
		i /= 10.0;
	return (num = num < 0.0 ? num - i : num + i);
}

/*
** save everything left of the dot with itoa
** add dot
** move numbers right of dot left and take the lowest with % 10
*/

char		*ft_f_itoa(double num, int prec)
{
	int			count;
	int			i;
	char		*integers;
	char		*temp;

	count = ncount(num);
	i = count + 1;
	prec = prec == -1 ? 6 : prec;
	num = round_up(num, prec + 1);
	temp = ft_strnew(prec + count);
	integers = ft_itoa(num);
	temp = ft_memcpy(temp, integers, count);
	temp[count] = prec == 0 ? 0 : '.';
	num = num < 0.0000000000 ? num * -1.0 : num;
	while (i < prec + count + 1)
	{
		temp[i++] = (unsigned long)(num * 10.0) % 10 + '0';
		num = (num - (int)num) * 10.0;
	}
	ft_strdel(&integers);
	return (temp);
}

long double	l_round_up(long double num, int prec)
{
	long double	i;
	int			n;

	n = prec;
	i = 5.0;
	while (n--)
		i /= 10.0;
	return (num = num < 0.0000000000 ? num - i : num + i);
}

char		*ft_lf_itoa(long double num, int prec)
{
	int			count;
	int			i;
	char		*integers;
	char		*temp;

	count = ncount(num);
	i = count + 1;
	prec = prec == -1 ? 6 : prec;
	num = round_up(num, prec + 1);
	temp = ft_strnew(prec + count);
	integers = ft_itoa(num);
	temp = ft_memcpy(temp, integers, count);
	temp[count] = prec == 0 ? 0 : '.';
	num = num < 0.0000000000 ? num * -1. : num;
	while (i < prec + count + 1)
	{
		temp[i++] = (long long)(num * 10.0) % 10 + '0';
		num = (num - (int)num) * 10.0;
	}
	free(integers);
	return (temp);
}
