/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improve_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 00:07:43 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/16 00:31:01 by bkonjuha         ###   ########.fr       */
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

static void	get_unused_paths(t_queue *new, t_queue *all, t_room *sink)
{
	t_queue *unused;
	t_queue *first_n;

	first_n = new;
	if (!(unused = (t_queue *)malloc(sizeof(t_queue))))
		ft_errno();
	while (all)
	{
		if (are_duplicates(all, new, sink) && !are_identical(new, all))
		{
			ft_printf("UNUSED \n");
			print_queue_id(all);
			unused = all;
			unused->parralel = NULL;
			unused = unused->parralel;
		}
		all = all->parralel;
	}
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
	get_unused_paths(new, first_a, sink);
}
