/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queueaddback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 18:41:03 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/24 18:43:45 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_queueaddback(t_queue **queue, t_queue *data)
{
	t_queue *new;
	t_queue *temp;

	new = ft_queuenew(data, sizeof(*data), data->id);
	new->called_by = data->called_by;
	new->id = data->id;
	temp = *queue;
	if (new)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
	{
		ft_errno();
	}
}
