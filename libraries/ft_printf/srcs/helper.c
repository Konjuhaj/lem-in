/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:35:00 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/24 15:45:27 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	typecast(t_data *data, long long *num)
{
	int id;

	id = data->type;
	*num = va_arg(data->arg, long long);
	if (data->length == 'h')
		*num = (short)*num;
	else if (data->length == 'h' + 'h')
		*num = (char)*num;
	else if (data->length == 'l')
		*num = (long)*num;
	if ((id == 'd' || id == 'i') && data->length == 0)
		*num = (int)*num;
}

void	u_typecast(t_data *data, unsigned long *bignum)
{
	*bignum = va_arg(data->arg, unsigned long);
	if (data->length == 'h')
		*bignum = (unsigned short)*bignum;
	else if (data->length == 'h' + 'h')
		*bignum = (unsigned char)*bignum;
	else if (data->length == 0)
		*bignum = (unsigned int)*bignum;
}

/*
** Centrelized filler
** precision behaves differently with 'f' type
*/

void	ft_fill(char *temp, t_data *data)
{
	char	*str;
	int		len;

	len = ft_strlen(temp);
	if (data->precision >= len)
	{
		str = dot_flag(temp, data);
		ft_strdel(&temp);
		temp = str;
	}
	else
	{
		str = data->hash == '#' ? hash_flag(temp, data) : temp;
		if (temp != str)
			ft_strdel(&temp);
		temp = str;
	}
	fill_buffer(str, data);
	if (data->precision >= len
		|| data->container.buffer[0] == '0' || data->sign)
		data->container.buffer = sign_flag(data, temp);
	if (temp)
		ft_strdel(&temp);
}

/*
** Move the str in buffer to the right
** to make space for a sign.
*/

void	move_right(t_data *data, char sign)
{
	int i;

	i = ft_strlen(data->container.buffer) - 1;
	while (--i >= 0)
		data->container.buffer[i + 1] = data->container.buffer[i];
	data->container.buffer[0] = sign;
}

/*
** if # is present we run c(temp) through hash_flag
** if prec > len (numbers get leading zeros | text is unchanged)
** else if prec < len(number is unchaned | text gets truncateds)
** lastly we add leading zeros if need be
*/

int		dot_validator(t_data *data, char **c, int *prec)
{
	int len;

	len = (int)ft_strlen(*c);
	if (data->container.id == NUMBER)
		*prec = data->precision < len ?
		len : data->precision;
	else if (data->container.id == TEXT)
		*prec = data->precision < len ?
		data->precision : len;
	return (0);
}
