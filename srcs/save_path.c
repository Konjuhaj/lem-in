/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:29:39 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/29 15:11:56 by bkonjuha         ###   ########.fr       */
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
	t_room *temp;

	i = 1;
	path = ft_dequeue(&queue);
	path->distance = 0;
	temp = path->content;
	temp->path = 1;
	while (path->id != first)
	{
		ft_queueaddfront(&path, ft_queuefind(&queue, path->called_by));
		temp = path->content;
		temp->path = 1;
		path->distance = i++;
	}
	print_queue_id(path);
	save_path(path, farm);
}
