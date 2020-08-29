/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_comb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 13:41:39 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/29 14:08:27 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_combinations	*short_comb(t_farm *farm)
{
	t_combinations	*comb;
	t_queue			*paths;
	t_queue			*temp;
	int i;

	comb = init_comb();
	i = -1;
	paths = copy_path(get_smallest(farm->paths, ++i));
	print_queue_id(paths);
	while (i < 40)
	{
		temp = get_smallest(farm->paths, ++i);
		if (!are_duplicates(temp, paths, farm->sink))
		{
			ft_printf("cat\n");
			while (paths->parralel)
				paths = paths->parralel;
			paths->parralel = copy_path(paths);
			paths = paths->parralel;
			paths->parralel = NULL;
			paths = comb->set;
		}
	}
	return (comb);
}
