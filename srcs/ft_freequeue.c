/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freequeue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:49:17 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/29 17:54:00 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_free_queue(t_queue *queue)
{
	t_queue *temp;

	temp = queue;
	while (temp)
	{
		queue = queue->next;
		free((void *)temp);
		temp = queue;
	}
}
