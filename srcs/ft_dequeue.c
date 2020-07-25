/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequeue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 10:11:15 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/25 13:03:17 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_queue	*ft_dequeue(t_queue **queue)
{
	t_queue *temp;

	temp = *queue;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		return (temp);
	}
	return (NULL);
}
