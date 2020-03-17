/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:37:05 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/25 15:43:04 by bkonjuha         ###   ########.fr       */
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
	if (!(BUFFER) || size < slen)
	{
		if (BUFFER)
			free(BUFFER);
		BUFFER = data->precision > -1 ?
		ft_strsub(s, 0, data->precision) : ft_strdup(s);
	}
	else
		fill_buffer(s, data);
	data->ret += ft_strlen(BUFFER);
}

/*
** set the second index to '\0' for strcpy to work.
** if !BUFFER we point buffer to c. If !c we print ^0
** else we add c to either the end or start of Buffer
*/

void	c_flag(t_data *data)
{
	char *c;

	c = ft_strnew(2);
	c[0] = va_arg(data->arg, int);
	c[1] = '\0';
	data->precision = 1;
	if (!BUFFER)
	{
		if (!(*c))
		{
			ft_putchar(*c);
			data->ret++;
		}
		BUFFER = c;
	}
	else if (!(*c))
	{
		BUFFER[data->allign == '-' ? 0 : data->size - 1] = '\0';
		data->ret++;
		free(c);
	}
	else
		ft_fill(c, data);
	data->ret += ft_strlen(BUFFER);
}

void	percent_flag(t_data *data)
{
	if (!(BUFFER))
		BUFFER = ft_strdup("%");
	else
		fill_buffer("%", data);
	data->ret += ft_strlen(BUFFER);
}
