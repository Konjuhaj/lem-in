/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queueaddfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 10:22:15 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/06/11 12:43:48 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_queueaddfront(t_queue **queue, t_queue *data)
{
	t_queue *new;

	new = ft_queuenew(data, sizeof(*data), data->id);
	new->called_by = data->called_by;
	new->id = data->id;
	if (new)
	{
		new->next = *queue;
		*queue = new;
	}
	else
	{
		ft_errno();
	}

}
