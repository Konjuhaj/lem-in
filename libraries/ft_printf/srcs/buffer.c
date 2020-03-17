/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:41:30 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/04 19:29:45 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Numbers get leading zeros with prec so we update buffer
**	size to prec if prec is larger that size
** else if number is is smaller than size we update part
**	of the buffer to zero for the input
*/

int		create_buffer(const char *s, t_data *data)
{
	int size;

	size = data->size;
	if (size > 0 && s)
	{
		if (data->precision > size && data->container.id == NUMBER)
		{
			size = data->precision;
			data->container.filler = '0';
			data->size = size;
		}
		BUFFER = ft_strnew(size + 1);
		ft_memset(BUFFER, data->container.filler, size);
		if (data->precision < data->size
			&& data->container.id == NUMBER
			&& data->precision != -1 && data->container.filler == '0'
			&& data->type != 'f')
		{
			data->container.filler = ' ';
			size = size - data->precision;
			while (--size >= 0)
				BUFFER[size] = data->container.filler;
		}
	}
	return (0);
}

/*
** function is called to move '-' to the start of number uffer
*/

char	*update_buffer(char *new)
{
	int		len;
	char	*final;

	len = ft_strlen(new) + 1;
	while (--len >= 0)
		if (new[len] == '-')
			new[len] = '0';
	final = ft_strjoin("-", new);
	return (final);
}

/*
** update temp (add prefix and leading zeros)
**	in casee of left alligned and prec >= temp lem
** free c if unsused
*/

void	fill_buffer(char *temp, t_data *data)
{
	size_t	start;
	size_t	destlen;
	size_t	srclen;
	int		precision;
	char	*c;

	c = temp;
	dot_validator(data, &c, &precision);
	destlen = ft_strlen(BUFFER);
	srclen = precision < 0 ? ft_strlen(c) : precision;
	if (srclen >= destlen && data->container.id == NUMBER)
	{
		free(BUFFER);
		BUFFER = ft_strdup(c);
	}
	else if (data->allign != '-')
	{
		start = destlen - srclen > 0 ? destlen - srclen : 0;
		ft_strncpy(BUFFER + start, c, destlen - start);
	}
	else
		ft_memcpy(BUFFER, c, srclen);
	if (c != temp && c != BUFFER && data->container.id == NUMBER)
		free(c);
}

void	add_buffer_postfix(t_data *data, char *postfix)
{
	char *temp;

	temp = ft_strjoin(BUFFER, postfix);
	free(BUFFER);
	BUFFER = temp;
}

void	add_buffer_prefix(char *prefix, t_data *data)
{
	char *temp;

	temp = ft_strjoin(prefix, BUFFER);
	free(BUFFER);
	BUFFER = temp;
}
