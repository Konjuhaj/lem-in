/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:54:49 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/09 15:34:08 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int	are_duplicates(t_queue *path, t_queue *set, t_room *sink)
{
	t_queue *base_path;
	t_queue *base_set;
	t_queue *set_path;

	base_path = path;
	base_set = set;
	while (set)
	{
		set_path = set;
		while (path->content != sink)
		{
			while (set_path->content != sink)
			{
				if (ft_strequ(path->id, set->id) == 1)
					return (1);
				set_path = set_path->next;
			}
			path = path->next;
			set_path = set;
		}
		// if (ft_strequ(path->id, set->id) == 0)
		// 	return (0);
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
