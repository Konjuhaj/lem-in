/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:37:05 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/24 15:45:27 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** default function for when an unknown param is added
*/

int		ft_default(int i)
{
	return (i);
}

/*
** if precision is below stringlen we set that as slen
** Unless presision is -1;
** Check with slen weather string fits into buffer
** if it doesn't fit we sub how much we need or dup.
*/

void	s_flag(t_data *data)
{
	char	*s;
	int		slen;
	int		size;

	s = va_arg(data->arg, char *);
	size = data->size;
	if (!s)
		s = "(null)";
	slen = ft_strlen(s);
	slen = data->precision > slen ? ft_strlen(s) : data->precision;
	slen = slen == -1 ? ft_strlen(s) : slen;
	if (!(data->container.buffer) || size < slen)
	{
		if (data->container.buffer)
			free(data->container.buffer);
		data->container.buffer = data->precision > -1 ?
		ft_strsub(s, 0, data->precision) : ft_strdup(s);
	}
	else
		fill_buffer(s, data);
	data->ret += ft_strlen(data->container.buffer);
}

/*
** set the second index to '\0' for strcpy to work.
** if !data->container.buffer we point buffer to c. If !c we print ^0
** else we add c to either the end or start of Buffer
*/

void	c_flag(t_data *data)
{
	char *c;

	c = ft_strnew(2);
	c[0] = va_arg(data->arg, int);
	c[1] = '\0';
	data->precision = 1;
	if (!data->container.buffer)
	{
		if (!(*c))
		{
			ft_putchar(*c);
			data->ret++;
		}
		data->container.buffer = c;
	}
	else if (!(*c))
	{
		data->container.buffer[data->allign == '-' ? 0 : data->size - 1] = '\0';
		data->ret++;
		free(c);
	}
	else
		ft_fill(c, data);
	data->ret += ft_strlen(data->container.buffer);
}

void	percent_flag(t_data *data)
{
	if (!(data->container.buffer))
		data->container.buffer = ft_strdup("%");
	else
		fill_buffer("%", data);
	data->ret += ft_strlen(data->container.buffer);
}
