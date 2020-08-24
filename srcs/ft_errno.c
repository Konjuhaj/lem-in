/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 16:09:28 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/24 15:19:25 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_errno(char *s, t_option *o)
{
	static t_option *op;

	if (!s)
		op = o;
	else
	{
		ft_putstr("ERROR\n");
		if (op->error)
			ft_putendl(s);
		exit(0);
	}
}
