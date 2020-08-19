/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:46:41 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/19 18:01:05 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	get_paths_in_use(t_combinations *comb, int ants)
{
	int arr[50];
	int i;
	int using;
	int	size;
	t_queue *temp;

	temp = comb->set;
	i = -1;
	using = 0;
	ft_bzero(&arr[0], sizeof(arr));
	while (temp)
	{
		arr[++i] = temp->distance;
		temp = temp->parralel;
	}
	sort_arr(&arr[0], i);
	size = i;
	i = 0;
	while (ants > 0 && size)
	{
		if (arr[i] < arr[i + 1] && i < size)
		{
			ants -= arr[i + 1] - arr[i];
			arr[i] += arr[i + 1] - arr[i];
			if (using < i + 1)
				using = i + 1;
			i = 0;
			continue ;
		}
		if (i == size)
		{
			arr[i] += 1;
			ants -= 1;
			i = 0;

		}
		i++;
	}
	comb->using = using;
}

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
		//get_paths_in_use(comb, farm->ants);
		//print_set(comb);
		path = path->parralel;
	}
	// comb->next = knapsack(farm->paths->set, farm->sink);
	// ft_printf("KNAPSACK SETT\n");
	// print_set(comb->next);
}
