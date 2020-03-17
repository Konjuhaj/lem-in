/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:27:25 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/05 11:43:54 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Add printing functons to f[]
** Add reading functions to f2[]
*/

void	function_array(void (*f[])(), int (*f2[])())
{
	f['c'] = &c_flag;
	f['s'] = &s_flag;
	f['S'] = &capital_s_flag;
	f['x'] = &x_flag;
	f['X'] = &x_flag;
	f['o'] = &o_flag;
	f['p'] = &p_flag;
	f['i'] = &d_flag;
	f['d'] = &d_flag;
	f['u'] = &d_flag;
	f['%'] = &percent_flag;
	f['f'] = &f_flag;
	f['b'] = &b_flag;
	f['B'] = &capital_b_flag;
	f['t'] = &t_flag;
	f['T'] = &capital_t_flag;
	f2[0] = &is_flag;
	f2[1] = &is_width;
	f2[2] = &is_precision;
	f2[3] = &is_legth;
	f2[4] = &is_type;
	f2[5] = &create_buffer;
	f2[6] = NULL;
}

/*
** run through all reader functions
** if data type is not recognized we go to default
** while there is str left we print
** or while there is size left we print
** if buffer is NULL we have 0 precision, 0 number and 0 width
*/

int		read_flags(const char *src, t_data *data, int i)
{
	void	(*function[126])(t_data *data, int id);
	int		(*params[7])(const char *s, t_data *data);
	int		remember;

	function_array(function, params);
	data->i = i + 1;
	remember = i + 1;
	i = -1;
	while (params[++i] != NULL)
		data->i = (params[i])(src + data->i, data) ? ++data->i : data->i;
	if (data->container.id == 0)
		return (ft_default(remember));
	function[(int)data->type](data, data->type);
	if (BUFFER == NULL)
		return (data->i);
	i = -1;
	while (++i < (int)ft_strlen(BUFFER) || i < data->size)
		ft_putchar(BUFFER[i]);
	return (data->i);
}

void	empty_struct(t_data *f)
{
	f->size = 0;
	f->sign = 0;
	f->hash = 0;
	f->allign = 0;
	f->precision = -1;
	f->container.id = 0;
	f->length = 0;
	f->container.buffer = NULL;
	f->length = 0;
}

/*
** if i exceeds the length of format we are
** at the end of format and out of bounds
** we continue to check if there is another % right after
*/

int		ft_printf(const char *format, ...)
{
	t_data	f;
	int		i;

	i = 0;
	f.ret = 0;
	va_start(f.arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			empty_struct(&f);
			i = read_flags(format, &f, i);
			ft_strdel(&f.container.buffer);
			f.container.buffer = NULL;
			if (ft_strlen(format) <= (size_t)i)
				break ;
			continue ;
		}
		f.ret++;
		ft_putchar(format[i++]);
	}
	va_end(f.arg);
	return (f.ret);
}
