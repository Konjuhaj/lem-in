/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 09:10:40 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/20 21:46:59 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	reset_ants(t_queue *queue)
{
	t_queue *temp;

	temp = queue;
	while (temp)
	{
		temp->ants = 0;
		temp = temp->parralel;
	}
}

t_combinations	*get_paths_in_use(t_combinations *comb)
{
	int		i;
	int		arr[150];
	t_queue	*temp;

	temp = comb->set;
	i = -1;
	ft_bzero(&arr[0], sizeof(arr));
	while (temp && i + 1 < 150)
	{
		arr[++i] = temp->distance;
		temp = temp->parralel;
	}
	comb->using = sort_arr(&arr[0], 149);
	return (comb);
}
