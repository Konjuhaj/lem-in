/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 09:10:40 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/20 11:35:20 by bkonjuha         ###   ########.fr       */
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

void	get_paths_in_use(t_combinations *comb)
{
	int i;
	t_queue *temp;

	temp = comb->set;
	i = -1;
	ft_bzero(&comb->using[0], sizeof(comb->using));
	while (temp)
	{
		comb->using[++i] = temp->distance;
		temp = temp->parralel;
	}
	sort_arr(&comb->using[0], i);
}
