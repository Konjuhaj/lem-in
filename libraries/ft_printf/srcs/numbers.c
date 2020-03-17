/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:50:40 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/25 15:34:05 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		x_flag(t_data *data)
{
	char			*temp;
	unsigned long	bignum;

	u_typecast(data, &bignum);
	temp = ft_uitoa_base(bignum, HEXAL);
	number_hub(data, temp);
}

/*
** if data type is 'u' we work with unsigned integers
*/

void		d_flag(t_data *data)
{
	long long		num;
	unsigned long	bignum;
	char			*temp;

	bignum = 0;
	if (data->type == 'u')
		u_typecast(data, &bignum);
	else
		typecast(data, &num);
	temp = data->type != 'u' ? ft_itoa_base(num, DECIMAL) :
						ft_uitoa_base(bignum, DECIMAL);
	number_hub(data, temp);
}

void		o_flag(t_data *data)
{
	char			*temp;
	unsigned long	bignum;

	bignum = 0;
	u_typecast(data, &bignum);
	temp = ft_uitoa_base(bignum, OCTAL);
	number_hub(data, temp);
}

/*
** Special case for when precision is defined and zero is passed
** data type and hash update to later add the prefix
** data type reseted in case 0 is passed with 0
*/

static void	p_flag_helper(t_data *data, char **temp2)
{
	char *temp3;

	if (data->precision >= 0 && ft_strlen(*temp2) < 2)
	{
		temp3 = ft_strnew((size_t)data->precision + 1);
		ft_memset(temp3, '0', data->precision);
		if (!(ft_strcmp(*temp2, "0")))
		{
			free(*temp2);
			*temp2 = temp3;
		}
	}
	data->hash = '#';
	data->type = 'x';
	if (data->precision == -1 && !ft_strcmp(*temp2, "0"))
		data->type = 'p';
}

/*
** Buffer removed in case temp doesn't fit into buffer
*/

void		p_flag(t_data *data)
{
	unsigned long	num;
	char			*temp2;

	num = va_arg(data->arg, unsigned long);
	temp2 = ft_uitoa_base(num, HEXAL);
	p_flag_helper(data, &temp2);
	if (!(BUFFER) || data->size < ((int)ft_strlen(temp2) + 2))
	{
		if (BUFFER)
			free(BUFFER);
		BUFFER = ft_strjoin("0x", temp2);
	}
	else
		ft_fill(ft_strdup(temp2), data);
	data->ret += ft_strlen(BUFFER);
	free(temp2);
}
