/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:46:41 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/09 15:27:36 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	size_of_set(t_combinations *set)
{
	int i;
	t_queue *temp;

	i = 0;
	temp = set->set;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_queue	*copy_path(t_queue *paths)
{
	t_queue *new;

	while (paths)
	{
		new = ft_queuenew(paths->content, paths->content_size, paths->id);
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
	int				size;
	t_combinations	*temp;
	t_queue			*path;

	size = size_of_set(farm->paths);
	temp = farm->paths;
	path = temp->set;
	while (path->parralel)
	{
		temp->next = new_set(path, farm->sink);
		temp = temp->next;
		path = path->parralel;
	}
}
