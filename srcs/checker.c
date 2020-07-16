/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:54:49 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/16 16:52:43 by bkonjuha         ###   ########.fr       */
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
				if (ft_strequ(path->id, set->id) == 1)
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

/*
** Might work without temp variables
**
*/

// int	are_duplicates(t_queue *new, t_queue *base, t_room *sink)
// {
// 	t_queue *base_new;
// 	t_queue *temp;
// 	t_queue *base_base;

// 	base_new = new;
// 	base_base = base;
// 	while (base_new)
// 	{
// 		temp = base_base;
// 		while (temp->content != sink)
// 		{
// 			if (ft_strequ(base_new->id, "11") == 1)
// 				return (0);
// 			else if (ft_strequ(temp->id, "11"))
// 				break ;
// 			else if (ft_strequ(temp->id, base_new->id) == 1)
// 				return (1);
// 			temp = temp->next;
// 		}
// 		base_new = base_new->next;
// 	}
// 	return (0);
// }
