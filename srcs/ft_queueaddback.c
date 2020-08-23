/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queueaddback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 22:04:12 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/23 20:48:23 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_queueaddback(t_queue **aqueue, t_queue *old)
{
	t_queue *new;
	t_queue *temp;

	new = ft_queuenew(old->content, sizeof(*old), old->id);
	new->called_by = old->called_by;
	new->id = old->id;
	temp = *aqueue;
	while (temp->next)
		temp = temp->next;
	if (new)
	{
		new->next = NULL;
		temp->next = new;
	}
	else
	{
		ft_errno();
	}
}
