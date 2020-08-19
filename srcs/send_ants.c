/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:37:39 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/19 20:28:47 by bkonjuha         ###   ########.fr       */
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
	while (comb && comb->next)
	{
		comb = comb->next;
		if (comb->max_flow <= ants)
		{
			if(comb->max_flow > temp->max_flow && comb->avg_speed < temp->avg_speed + 2)
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
			if (temp->distance + temp->ants <= shortest->distance + shortest->ants)
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

static void				move_ant(t_queue *temp, t_queue *prev, t_queue *end, int *s_a)
{
	prev->c_ant = temp->c_ant;
	temp->c_ant = 0;
	if (prev->id == end->id)
		*s_a += 1;
	ft_printf("L%d-%s ", prev->c_ant, prev->id);
}

static void				send_ant(t_queue *prev)
{
	static int ant_number;

	prev->ants--;
	prev->c_ant = ++ant_number;
	ft_printf("L%d-%s ", prev->c_ant, prev->id);
	// *s_a += 1;
}

static void				move_ants(t_combinations *comb, t_queue *end,  int ants)
{
	t_queue *temp;
	t_queue * prev;
	t_queue *set;
	int		sink_ants;
	int 	i;

	i = 0;
	sink_ants = 0;
	while (sink_ants < ants)
	{
		i++;
		set = comb->set;
		while (set && set->previous)
		{
			prev = set->previous;
			while (prev && set != prev)
			{
				temp = prev->previous;
				if (temp->c_ant && !prev->c_ant)
					move_ant(temp, prev, end, &sink_ants);
				else if (prev->id == end->id && temp->c_ant)
					move_ant(temp, prev, end, &sink_ants);
				prev = prev->previous;
			}
			if (prev->ants > 0 && prev->c_ant == 0)
				send_ant(prev);
			set = set->parralel;
		}
		write(1, "\n", 1);
		// ft_printf("%d vs %d\n", sink_ants, ants);
	}
}

static void		connect_queue(t_queue *path, t_room *sink)
{
	t_queue *temp = path;

	while (temp->content != sink)
		temp = temp->next;
	path->previous = temp;
}

static void				reverse_connect(t_combinations *comb, t_room *sink)
{
	t_queue *current;
	t_queue *previous;
	t_queue *set;

	set = comb->set;
	while (set && set->next)
		{
		current = set->next;
		previous = set;
		while(current && current->content != sink)
		{
			current->previous = previous;
			current = current->next;
			previous = previous->next;
		}
		if (!current)
			break ;
		current->previous = previous;
		connect_queue(set, sink);
		set = set->parralel;
	}
}

void					send_ants(t_farm *farm)
{
	t_combinations	*best_comb;

	best_comb = best_path(farm->paths->next, farm->ants);
	calculate_ants_per_path(best_comb, farm->ants);
	remove_unused(best_comb->set);
	improve_set(best_comb->set, farm->paths->set, farm->sink);
	// print_set(best_comb); // testing
	reverse_connect(best_comb, farm->sink);
	move_ants(best_comb, get_sink(best_comb, farm->sink), farm->ants);
}
