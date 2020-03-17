/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:30:36 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/25 16:47:30 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	capital_s_flag(t_data *data)
{
	char	**str;
	char	*temp;
	int		j;

	str = va_arg(data->arg, char**);
	j = -1;
	if (BUFFER)
		free(BUFFER);
	BUFFER = str[++j];
	while (str[++j])
	{
		temp = ft_strjoin(BUFFER, str[j]);
		free(BUFFER);
		BUFFER = temp;
		if (data->length == 'h' && str[j + 1] != NULL)
			add_buffer_postfix(data, "\n");
	}
}

void	b_flag(t_data *data)
{
	int c;

	c = va_arg(data->arg, int);
	ft_printbit(c);
	data->ret += 8;
}

void	capital_b_flag(t_data *data)
{
	char	*temp;
	int		i;

	i = -1;
	temp = va_arg(data->arg, char *);
	while (temp[++i])
		ft_printbit(temp[i]);
	data->ret += i * 8;
}

void	t_flag(t_data *data)
{
	t_list *lst;

	lst = va_arg(data->arg, t_list *);
	ft_putstr(lst->content);
	data->ret += lst->content_size;
}

void	capital_t_flag(t_data *data)
{
	t_list *head;

	head = va_arg(data->arg, t_list *);
	ft_lstputstr(head);
}
