/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:46:41 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/10 10:00:53 by bkonjuha         ###   ########.fr       */
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

t_queue	*copy_path(t_queue *paths)
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

t_combinations	*new_set(t_queue *paths, t_room *sink)
{
	t_queue *base;
	t_queue *temp_new;
	t_combinations *new;

	base = paths;
	if (!(new = (t_combinations *)malloc(sizeof(t_combinations) + 1)))
		ft_errno();
	new->set = copy_path(paths);
	temp_new = new->set;
	while (base->parralel)
	{
		if (!are_duplicates(base->parralel, new->set, sink))
		{
			temp_new->parralel = copy_path(base->parralel);
			temp_new = temp_new->parralel;
		}
		base = base->parralel;
	}
	return (new);
}

void	combinations(t_farm *farm)
{
	t_combinations	*temp;
	t_queue			*path;

	temp = farm->paths;
	path = temp->set;
	while (path->parralel)
	{
		temp->next = new_set(path, farm->sink);
		temp = temp->next;
		update_combination(temp);
		path = path->parralel;
	}
}
