/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improve_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 00:07:43 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/18 17:35:32 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			are_identical(t_queue *new, t_queue *all)
{
	while(new && all)
	{
		if (new->content != all->content)
			return (0);
		new = new->next;
		all = all->next;
	}
	return (1);
}

void improve_set(t_queue *new, t_queue *all, t_room *sink)
{
	t_queue *first_n;
	t_queue *first_a;

	first_n = new;
	first_a = all;
	while (all)
	{
		if (!are_duplicates(all, new, sink))
		{
			while (new->parralel)
				new = new->parralel;
			new->parralel = copy_path(all);
			new = new->parralel;
			new->parralel = NULL;
			new = first_n;
		}
		all = all->parralel;
	}
}
