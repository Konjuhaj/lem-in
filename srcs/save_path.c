/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:29:39 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/09 11:16:40 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	save_path(t_queue *path, t_farm *farm)
{
	t_queue			*temp;

	if (!farm->paths->set)
	{
		farm->paths->set = path;
		farm->paths->set->parralel = NULL;
	}
	else
	{
		temp = farm->paths->set;
		while (temp->parralel)
			temp = temp->parralel;
		temp->parralel = path;
		temp = temp->parralel;
		temp->parralel = NULL;
	}
}
