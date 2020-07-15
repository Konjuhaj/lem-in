/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:37:39 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/15 14:24:40 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

/* WIP
**	if statments could be done with tenary opperator
**	// might be able to calculate with the amount of rooms in comb per path
*/

static t_combinations	*best_path(t_combinations *comb, int ants)
{
	t_combinations *temp;

	temp = comb;
	while (comb->next)
	{
		comb = comb->next;
		if (comb->max_flow <= ants)
		{
			if(comb->max_flow > temp->max_flow)
				temp = comb;
			else if (comb->avg_speed < temp->avg_speed && comb->max_flow == temp->max_flow)
				temp = comb;
		}
		else if (comb->max_flow > ants && temp->avg_speed > comb->avg_speed)
		{
			temp = comb;
		}
	}
	return (temp);
}

static void				calculate_ants_per_path(t_combinations *comb, int ants)
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
			if (temp->distance + temp->ants < shortest->distance + shortest->ants)
				shortest = temp;
			temp = temp->parralel;
		}
		temp = comb->set;
		shortest->ants++;
		ant_set--;
	}
}

static t_queue				*get_sink(t_combinations *comb, t_room *sink)
{
	t_queue *end;

	end = comb->set;
	while (end->content != sink)
		end = end->next;
	return (end);
}

static void				move_ants(t_combinations *comb, t_queue *end,  int ants)
{
	t_queue *temp;
	t_queue * prev;
	t_queue *set;
	int		sink_ants;

	sink_ants = 0;
	while (sink_ants < ants)
	{
		set = comb->set;
		temp = comb->set->previous;
		while (set)
		{
			prev = set->previous;
			while (prev->id != set->id)
			{
				ft_printf("%s -> %p && %p <- %s\n", prev->id, prev->id, set->id, set->id);
				temp = prev->previous;
				if (temp->c_ant == 0 && prev->c_ant == 1)
				{
					temp->c_ant++;
					if (temp->content == end)
						sink_ants++;
					prev->c_ant--;
					ft_printf("Moving an ant");
				}
				prev = prev->previous;
			}
			if (prev->ants > 0 && prev->c_ant == 0)
			{
				prev->ants--;
				prev->c_ant++;
			}
			set = set->parralel;
		}
	}
}

void					send_ants(t_farm *farm)
{
	t_combinations	*best_comb;

	best_comb = best_path(farm->paths->next, farm->ants);
	calculate_ants_per_path(best_comb, farm->ants);
	move_ants(best_comb, get_sink(best_comb, farm->sink), farm->ants);
	print_set(best_comb); // testing
}
