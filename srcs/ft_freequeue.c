/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freequeue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:49:17 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/02 15:03:10 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_free_queue(t_queue *base)
{
	t_queue *queue;

	queue = base->next;
	free((void *)base);
	while (queue)
	{
		base = queue;
		queue = queue->next;
		free((void *)base);
	}
}
