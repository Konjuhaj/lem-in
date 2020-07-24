/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:37:39 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/24 14:45:16 by bkonjuha         ###   ########.fr       */
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
	temp->c_ant--;
	//ft_printf("%p -> %p && %p <- %s\n", prev->id, prev, end, end->id);
	if (prev->id == end->id)
		*s_a += 1;
	prev->c_ant++;
	ft_printf("L%s -> %s ", temp->id, prev->id);
}

static void				send_ant(t_queue *prev)
{
	prev->ants--;
	ft_printf("Lstart -> %s ", prev->id);
	prev->c_ant++;
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
		set = comb->set;
		while (set && set->previous)
		{
			prev = set->previous;
			while (prev && set != prev)
			{
				temp = prev->previous;
				if (temp->c_ant == 1 && prev->c_ant == 0)
					move_ant(temp, prev, end, &sink_ants);
				else if (prev->id == end->id && temp->c_ant == 1)
					move_ant(temp, prev, end, &sink_ants);
				prev = prev->previous;
			}
			if (prev->ants > 0 && prev->c_ant == 0)
				send_ant(prev);
			set = set->parralel;
		}
		write(1, "\n", 1);
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
	//print_set(best_comb); // testing
	reverse_connect(best_comb, farm->sink);
	move_ants(best_comb, get_sink(best_comb, farm->sink), farm->ants);
}
