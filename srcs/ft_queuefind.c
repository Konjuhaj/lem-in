/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuefind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 10:27:19 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/23 20:48:55 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	*ft_queuefind(t_queue **queue, char *id)
{
	t_queue *temp;

	temp = *queue;
	while (temp && temp->id != id)
	{
		temp = temp->next;
	}
	if (!temp)
		ft_errno();
	return (temp);
}
