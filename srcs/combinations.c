/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:46:41 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/23 20:26:30 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

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
	t_queue			*temp_new;
	t_combinations	*new;

	new = init_comb();
	new->set = copy_path(current);
	temp_new = new->set;
	while (paths)
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

void	combinations(t_farm *farm)
{
	t_combinations	*comb;
	t_queue			*path;

	comb = farm->paths;
	path = comb->set;
	farm->paths = get_paths_in_use(farm->paths);
	while (path)
	{
		comb->next = new_set(farm->paths->set, path, farm->sink);
		comb = comb->next;
		calculate_ants_per_path(comb, farm->ants);
		remove_unused(comb->set);
		improve_set2(comb->set, farm->paths, farm->sink);
		reset_ants(comb->set);
		calculate_ants_per_path(comb, farm->ants);
		update_length(comb);
		path = path->parralel;
	}
}
