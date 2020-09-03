/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 09:10:40 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/09/02 23:07:27 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			reset_ants(t_queue *queue)
{
	t_queue *temp;

	temp = queue;
	while (temp)
	{
		temp->ants = 0;
		temp = temp->parralel;
	}
}

void			calculate_ants_per_path(t_combinations *comb, int ants)
{
	t_queue *temp;
	t_queue *shortest;
	int		ant_set;

	temp = comb->set;
	shortest = comb->set;
	ant_set = ants;
	while (ant_set)
	{
		while (temp)
		{
			if (temp->distance + temp->ants <
				shortest->distance + shortest->ants)
				shortest = temp;
			temp = temp->parralel;
		}
		temp = comb->set;
		shortest->ants++;
		ant_set--;
	}
}

t_combinations	*get_paths_in_use(t_combinations *comb)
{
	int		i;
	int		*arr;
	t_queue	*temp;

	temp = comb->set;
	i = -1;
	arr = ft_memalloc(150);
	ft_bzero(arr, sizeof(arr));
	while (temp && i + 1 < 150)
	{
		arr[++i] = temp->distance;
		temp = temp->parralel;
	}
	comb->using = sort_arr(arr, i);
	return (comb);
}

void			update_length(t_combinations *comb)
{
	t_queue	*temp;
	int		longest;

	temp = comb->set;
	longest = temp->distance + temp->ants;
	while (temp)
	{
		if (temp->distance + temp->ants > longest)
			longest = temp->distance + temp->ants;
		temp = temp->parralel;
	}
	comb->print = longest;
}

t_combinations	*best_path(t_combinations *comb)
{
	t_combinations	*temp;
	t_combinations	*better;
	int				shortest;

	shortest = comb->print;
	better = comb;
	temp = comb;
	while (temp)
	{
		if (temp->print < shortest)
		{
			shortest = temp->print;
			better = temp;
		}
		temp = temp->next;
	}
	return (better);
}
