/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_comb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 13:41:39 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/09/02 16:26:57 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_combinations	*short_comb(t_farm *farm)
{
	t_combinations	*comb;
	t_queue			*paths;

	comb = init_comb();
	paths = copy_path(farm->paths->set);
	paths->parralel = NULL;
	comb->set = paths;
	improve_set2(paths, farm->paths, farm->sink);
	calculate_ants_per_path(comb, farm->ants);
	update_length(comb);
	return (comb);
}
