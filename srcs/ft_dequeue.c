/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequeue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 10:11:15 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/26 19:57:47 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_queue	*ft_dequeue(t_queue **queue)
{
	t_queue *temp;
	t_queue *new;

	temp = *queue;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		new = ft_queuenew(temp->content, temp->content_size, temp->id);
		new->called_by = temp->called_by;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
