/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:46:41 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/14 11:18:58 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	update_combination(t_combinations *comb)
{
	t_queue *temp;

	temp = comb->set;
	comb->avg_speed = 0.0;
	comb->max_flow = 0;
	while (temp)
	{
		comb->max_flow++;
		comb->avg_speed += (double)temp->distance;
		temp = temp->parralel;
	}
	comb->avg_speed /= (double)comb->max_flow;
}

t_queue			*copy_path(t_queue *paths)
{
	t_queue *new;

	while (paths)
	{
		new = ft_queuenew(paths->content, paths->content_size, paths->id);
		new->distance = paths->distance;
		new->next = copy_path(paths->next);
		return (new);
	}
	return (NULL);
}

t_combinations	*new_set(t_queue *paths, t_queue *current, t_room *sink)
{
	t_queue *temp_new;
	t_combinations *new;

	if (!(new = (t_combinations *)malloc(sizeof(t_combinations) + 1)))
		ft_errno();
	new->set = copy_path(current);
	temp_new = new->set;
	while (paths->parralel)
	{
		if (!are_duplicates(paths, new->set, sink))
		{
			temp_new->parralel = copy_path(paths);
			temp_new = temp_new->parralel;
		}
		paths = paths->parralel;
	}
	temp_new->parralel = NULL;
	new->next = NULL;
	return (new);
}

static void improve_set(t_queue *new, t_queue *all, t_room *sink)
{
	t_queue *first_n;

	first_n = new;
	while (all)
	{
		if (!are_duplicates(all, new, sink))
		{
			while (new->parralel)
				new = new->parralel;
			new->parralel = copy_path(all);
			new = new->parralel;
			new->parralel = NULL;
			new = first_n;
		}
		all = all->parralel;
	}
}

void	combinations(t_farm *farm)
{
	t_combinations	*comb;
	t_queue			*path;

	comb = farm->paths;
	path = comb->set;
	while (path->parralel)
	{
		comb->next = new_set(farm->paths->set, path, farm->sink);
		comb = comb->next;
		improve_set(comb->set, farm->paths->set, farm->sink);
		update_combination(comb);
		path = path->parralel;
	}
}
