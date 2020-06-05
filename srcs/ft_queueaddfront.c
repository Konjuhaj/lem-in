/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queueaddfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 10:22:15 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/06/04 10:53:29 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_queueaddfront(t_queue **queue, t_queue *new)
{
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
