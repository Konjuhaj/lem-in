/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 08:24:02 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/05 11:48:14 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** we don't add a prefic unless it's a pointer
** if there are leading we add an x to the second index
** else we add the appropriate prefix
*/

char	*hash_flag(char *s, t_data *data)
{
	char *temp;

	temp = NULL;
	if (!ft_strcmp(s, "0") && data->type != 'p')
		return (s);
	else if (data->container.filler == '0')
	{
		if (data->type == 'x')
			BUFFER[1] = data->type;
	}
	else if (data->type == 'x' || data->type == 'X' || data->type == 'p')
		temp = ft_strjoin("0x", s);
	else if (data->type == 'o' && s[0] != '0')
		temp = ft_strjoin("0", s);
	return (temp == NULL ? s : temp);
}

/*
** Add leading zeros to temp by getting
** the difference of temp and precision
** if # is present we add a
*/

char	*dot_flag(char *c, t_data *data)
{
	char	*temp;
	char	*prefix;
	int		len;
	int		padding;

	len = ft_strlen(c);
	padding = data->precision - len;
	temp = ft_strnew(data->precision + 1);
	data->container.filler = '0';
	ft_memset(temp, data->container.filler, data->precision);
	ft_strncpy(temp + padding, c, len);
	if (data->hash == '#' || c[0] == '-')
	{
		if (data->hash == '#')
		{
			data->container.filler = 0;
			prefix = hash_flag(temp, data);
		}
		else
			prefix = update_buffer(temp);
		if (prefix != temp)
			free(temp);
		temp = prefix;
	}
	return (temp);
}

/*
** this fuction is called only if '-' is misplaced
** replace '-' with a '0'
** if precision is undefined leading zeros are are index 0
** if there is no space to move right we append a '-'
*/

void	minus_flag(t_data *data, char sign)
{
	int i;
	int slen;
	int space;

	sign = sign + 1;
	space = data->size;
	slen = ft_strlen(BUFFER);
	i = 0;
	while (BUFFER[i] != '-' && BUFFER[i])
		i++;
	BUFFER[i] = '0';
	if (BUFFER[0] == ' ')
	{
		i = 0;
		while (!ft_isalnum(BUFFER[i]))
			i++;
		BUFFER[i - 1] = '-';
	}
	else if (data->precision == -1)
		BUFFER[0] = '-';
}

/*
** we only print a sign if there is no space to move_right
**	or if we don't have leading spaces
** else if left alligned ther must be space so we move it to the right
** else is must be right aligned with leading spaces
*/

void	plus_flag(t_data *data, char sign, int len)
{
	int		space;
	int		i;

	space = data->size;
	i = 0;
	if (BUFFER[0] != ' ' && (space <= data->precision
			|| space == 0 || space <= len))
	{
		ft_putchar(data->sign);
		data->ret++;
	}
	else if (data->allign == '-')
		move_right(data, sign);
	else
	{
		while (BUFFER[i] == ' ')
			i++;
		BUFFER[i == 0 ? 0 : i - 1] = data->sign;
	}
}

char	*sign_flag(t_data *data, char *temp)
{
	char	sign;
	int		len;
	int		size;

	len = ft_strlen(temp);
	size = data->precision;
	sign = temp[0] == '-' ? '-' : 0;
	BUFFER = BUFFER == NULL ? ft_strnew(1) : BUFFER;
	if (data->sign > 0 && sign != '-')
		sign = data->sign;
	if (sign && sign != '-' && data->container.id == NUMBER
		&& data->type != 'u')
		plus_flag(data, sign, len);
	else if (temp[0] == '-' && data->container.filler == '0'
			&& (size >= len || size == -1))
		minus_flag(data, sign);
	return (BUFFER);
}
