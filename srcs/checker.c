/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:54:49 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/29 15:07:47 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int	are_duplicates(t_queue *path, t_queue *set, t_room *sink)
{
	t_queue *base_set;
	t_queue *base_path;

	base_set = set;
	base_path = path;
	while (set)
	{
		while (path && path->content != sink)
		{
			while (set && set->content != sink)
			{
				if (path->content == set->content)
					return (1);
				set = set->next;
			}
			set = base_set;
			path = path->next;
		}
		base_set = base_set->parralel;
		set = base_set;
		path = base_path;
	}
	return (0);
}
