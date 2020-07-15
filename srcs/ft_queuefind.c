/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuefind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 10:27:19 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/15 10:58:28 by bkonjuha         ###   ########.fr       */
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
		ft_printf("ID(%s) NOT FOUND", id);
	return (temp);
}
