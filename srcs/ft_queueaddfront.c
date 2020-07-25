/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queueaddfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 10:22:15 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/25 13:06:45 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_queueaddfront(t_queue **aqueue, t_queue *old)
{
	t_queue *new;

	new = ft_queuenew(old->content, sizeof(*old), old->id);
	new->called_by = old->called_by;
	new->id = old->id;
	if (new)
	{
		new->next = *aqueue;
		*aqueue = new;
	}
	else
	{
		ft_errno();
	}
}
