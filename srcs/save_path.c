/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:29:39 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/09/02 22:08:58 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	path_exists(t_queue *new, t_queue *all)
{
	t_queue *first_n;
	t_queue *first_a;

	first_n = new;
	while (all)
	{
		first_a = all;
		if (are_identical(new, all))
			return (1);
		all = first_a;
		all = all->parralel;
		new = first_n;
	}
	return (0);
}

void		save_path(t_queue *path, t_farm *farm)
{
	t_queue *temp;

	if (!farm->paths->set)
	{
		farm->paths->set = path;
		farm->paths->set->parralel = NULL;
	}
	else
	{
		if (!path_exists(path, farm->paths->set) && path->distance < 105)
		{
			temp = farm->paths->set;
			while (temp->parralel)
				temp = temp->parralel;
			temp->parralel = path;
			temp = temp->parralel;
			temp->parralel = NULL;
		}
		else
			ft_free_queue(path);
	}
}

t_queue		*store_path(t_queue *queue, char *first, t_farm *farm)
{
	int		i;
	t_queue	*path;
	t_queue *last;
	t_room	*temp;

	i = 1;
	path = ft_dequeue(&queue);
	temp = path->content;
	last = ft_queuefind(&queue, path->called_by);
	ft_queueaddback(&path, last);
	while (last->id != first)
	{
		last = ft_queuefind(&queue, last->called_by);
		ft_queueaddback(&path, last);
		temp = last->content;
		path->distance = i++;
	}
	last = path->next;
	last->distance = path->distance;
	free((void *)path);
	path = ft_queuenew(farm->sink, sizeof(t_room), farm->sink->name);
	ft_queueaddback(&last, path);
	free((void *)path);
	return (last);
}
