/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:29:39 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/20 18:31:01 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	path_exists(t_queue *new, t_queue *all)
{
	t_queue *first_n;
	t_queue *first_a;
	int		fine;

	first_n = new;
	while (all)
	{
		first_a = all;
		fine = 1;
		fine = are_identical(new, all);
		if (fine)
			return (1);
		all = first_a;
		all = all->parralel;
		new = first_n;
	}
	return (0);
}

void		save_path(t_queue *path, t_farm *farm)
{
	t_queue			*temp;
	// static int d;


	if (!farm->paths->set)
	{
		// ft_printf("%d %d ==> ", ++d, path->distance);
		// print_queue_id(path);
		farm->paths->set = path;
		farm->paths->set->parralel = NULL;
	}
	else
	{
		if (!path_exists(path, farm->paths->set))
		{
			// ft_printf("%d %d ==> ", ++d, path->distance);
			// print_queue_id(path);
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
	t_room *temp;

	i = 0;
	path = ft_dequeue(&queue);
	path->distance = 0;
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
	// static int d;
	// ft_printf("%d == ", ++d);
	// print_queue_id(last);
	ft_queueaddback(&last, ft_queuenew(farm->sink, sizeof(t_room), farm->sink->name));
	save_path(last, farm);
	return (last);
}
