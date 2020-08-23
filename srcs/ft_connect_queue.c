/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect_queue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 19:03:53 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/23 21:09:20 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	ft_connect_queue(t_queue *path, t_room *sink)
{
	t_queue *temp;

	temp = path;
	while (temp->content != sink)
		temp = temp->next;
	path->previous = temp;
}

void	reverse_connect(t_combinations *comb, t_room *sink)
{
	t_queue *current;
	t_queue *previous;
	t_queue *set;

	set = comb->set;
	while (set && set->next)
	{
		current = set->next;
		previous = set;
		while (current && current->content != sink)
		{
			current->previous = previous;
			current = current->next;
			previous = previous->next;
		}
		if (!current)
			break ;
		current->previous = previous;
		ft_connect_queue(set, sink);
		set = set->parralel;
	}
}
