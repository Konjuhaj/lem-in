/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:37:39 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/24 17:58:30 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void	move_ant(t_queue *temp, t_queue *prev, t_queue *end, int *s_a)
{
	prev->c_ant = temp->c_ant;
	temp->c_ant = 0;
	if (prev->id == end->id)
		*s_a += 1;
	ft_printf("L%d-%s ", prev->c_ant, prev->id);
}

static void	send_ant(t_queue *prev)
{
	static int ant_number;

	if (prev->ants > 0 && prev->c_ant == 0)
	{
		prev->ants--;
		prev->c_ant = ++ant_number;
		ft_printf("L%d-%s ", prev->c_ant, prev->id);
	}
}

static void	move_ants(t_combinations *comb, t_queue *end, int ants)
{
	t_queue		*temp;
	t_queue		*prev;
	t_queue		*set;
	static int	sink_ants;

	while (sink_ants < ants)
	{
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
			send_ant(prev);
			set = set->parralel;
		}
		write(1, "\n", 1);
	}
}

void		send_ants(t_farm *farm)
{
	t_combinations	*best_comb;

	best_comb = best_path(farm->paths->next);
	reverse_connect(best_comb, farm->sink);
	move_ants(best_comb, best_comb->set->previous, farm->ants);
}
