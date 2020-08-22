/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:46:41 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/20 23:25:47 by bkonjuha         ###   ########.fr       */
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
	t_queue			*temp_new;
	t_combinations	*new;
	int				i;

	if (!(new = (t_combinations *)malloc(sizeof(t_combinations) + 1)))
		ft_errno();
	new->set = copy_path(current);
	temp_new = new->set;
	i = 0;
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
	int				i;

	comb = farm->paths;
	path = comb->set;
	i = 0;
	farm->paths = get_paths_in_use(farm->paths);
	while (path)
	{
		if (i++ > 80)
			break ;
		comb->next = new_set(farm->paths->set, path, farm->sink);
		comb = comb->next;
		update_combination(comb);
		//print_set(comb);
		path = path->parralel;
	}
}
