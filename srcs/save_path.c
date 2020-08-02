/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:29:39 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/01 21:07:25 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		save_path(t_queue *path, t_farm *farm)
{
	t_queue			*temp;

	if (!farm->paths->set)
	{
		farm->paths->set = path;
		farm->paths->set->parralel = NULL;
	}
	else
	{
		temp = farm->paths->set;
		while (temp->parralel)
			temp = temp->parralel;
		temp->parralel = path;
		temp = temp->parralel;
		temp->parralel = NULL;
	}
}

void		store_path(t_queue *queue, char *first, t_farm *farm)
{
	int		i;
	t_queue	*path;
	t_queue *last;
	t_room *temp;

	i = 0;
	path = ft_dequeue(&queue);
	path->distance = 0;
	temp = path->content;
	temp->path = 1;
	last = ft_queuefind(&queue, path->called_by);
	ft_queueaddback(&path, last);
	while (last->id != first)
	{
		last = ft_queuefind(&queue, last->called_by);
		ft_queueaddback(&path, last);
		temp = last->content;
		temp->path = 1;
		path->distance = i++;
	}
	last = path->next;
	last->distance = path->distance;
	//print_queue_id(last);
	save_path(last, farm);
}
