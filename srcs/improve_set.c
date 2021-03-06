/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improve_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 00:07:43 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/09/02 23:07:43 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			are_identical(t_queue *new, t_queue *all)
{
	while (new && all)
	{
		if (new->content != all->content)
			return (0);
		new = new->next;
		all = all->next;
	}
	return (1);
}

void		remove_unused(t_queue *queue)
{
	t_queue *temp;
	t_queue *temp2;

	temp = queue->parralel;
	temp2 = queue;
	while (temp)
	{
		if (temp->ants == 0)
		{
			temp2->parralel = temp->parralel;
			ft_free_queue(temp);
			temp = temp2->parralel;
			continue ;
		}
		temp = temp->parralel;
		temp2 = temp2->parralel;
	}
}

t_queue		*get_smallest(t_combinations *comb, int i)
{
	t_queue *temp;

	temp = comb->set;
	while (temp && temp->distance != comb->using[i])
	{
		temp = temp->parralel;
	}
	return (temp);
}

void		add_queue(t_queue *all, t_queue *new)
{
	t_queue *temp;

	temp = all;
	while (temp->parralel)
		temp = temp->parralel;
	temp->parralel = copy_path(new);
	temp = temp->parralel;
	temp->parralel = NULL;
}

void		improve_set2(t_queue *new, t_combinations *farm, t_room *sink)
{
	t_queue	*first_n;
	t_queue	*all;
	int		i;

	first_n = new;
	i = -1;
	while ((all = get_smallest(farm, ++i)))
	{
		if (i == 40)
			break ;
		if (!are_duplicates(all, new, sink))
		{
			add_queue(new, all);
			new = first_n;
		}
	}
}
