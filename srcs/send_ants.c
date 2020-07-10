/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:37:39 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/10 16:00:18 by bkonjuha         ###   ########.fr       */
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
		else if (comb->max_flow > ants && temp->avg_speed < comb->avg_speed)
			temp = comb;
	}
	return (temp);
}

void					send_ants(t_farm *farm)
{
	t_combinations	*best_comb;

	best_comb = best_path(farm->paths->next, farm->ants);
	print_set(best_comb);
}
