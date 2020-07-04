/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:38:36 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/04 17:41:14 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		print_queue_id(t_queue *queue)
{
	t_queue *temp;

	temp = queue;
	while (temp)
	{
		ft_printf("%s -> ", temp->id);
		temp = temp->next;
	}
	ft_putstr("\n");
}

