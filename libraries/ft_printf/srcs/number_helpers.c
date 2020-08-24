/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 06:35:00 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/24 15:51:28 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** If there is a buffer we remove it
** Append temp to Buffer either through hash or directly
** if Precision > buffer we add leading zeros
*/

static void	append_str_to_buffer(t_data *data, char *temp)
{
	if (data->container.buffer)
		free(data->container.buffer);
	if (data->precision > (int)ft_strlen(temp))
		data->container.buffer = dot_flag(temp, data);
	else
		data->container.buffer = data->hash == '#' ?
			hash_flag(temp, data) : temp;
	if (data->sign != 0 || (temp[0] == '-' && data->container.buffer[0] == '0'))
		data->container.buffer = sign_flag(data, temp);
	if (data->container.buffer != temp)
		free(temp);
}

/*
** we output nothing if number is 0 and precision is 0
** unless # is active with 'o' flag or
** '+'/' ' is active with d/i flag
*/

static void	zero_precision_w_zero_num(t_data *data, char *temp)
{
	if (data->hash == '#' && data->type == 'o')
		data->container.buffer = ft_strdup("0");
	data->ret += data->container.buffer == NULL ?
		0 : ft_strlen(data->container.buffer);
	if ((data->type == 'd' || data->type == 'i')
		&& (data->sign == '+' || data->sign == ' '))
		data->container.buffer = sign_flag(data, temp);
	free(temp);
}

/*
** Centrelized Number function
*/

void		number_hub(t_data *data, char *temp)
{
	data->sign = temp[0] == '-' ? 0 : data->sign;
	if (temp[0] == '0' && data->precision == 0)
		zero_precision_w_zero_num(data, temp);
	else
	{
		if (!(data->container.buffer) || data->size <= (int)ft_strlen(temp))
			append_str_to_buffer(data, temp);
		else
			ft_fill(temp, data);
		if (data->type == 'X')
			ft_capitalize(data->container.buffer);
		data->ret += ft_strlen(data->container.buffer);
	}
}
