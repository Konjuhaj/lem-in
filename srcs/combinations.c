/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:46:41 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/09 11:56:09 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

/*
** Might work without temp variables
**
*/

static int	are_duplicates(t_queue *path1, t_queue *path2)
{
	t_queue *base1;
	t_queue *temp2;
	t_queue *base2;

	base1 = path1;
	base2 = path2;
	while (base1)
	{
		temp2 = base2;
		while (temp2)
		{
			if (ft_strequ(base1->id, "11") == 1)
				return (0);
			else if (ft_strequ(temp2->id, "11"))
				break ;
			else if (ft_strequ(temp2->id, base1->id) == 1)
			{
				ft_printf("%s vs %s\n", base1->id, temp2->id);
				return (1);
			}
			temp2 = temp2->next;
		}
		base1 = base1 ->next;
	}
	return (0);
}

static int	size_of_set(t_combinations *set)
{
	int i;
	t_queue *temp;

	i = 0;
	temp = set->set;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_queue	*copy_path(t_queue *paths)
{
	t_queue *new;

	while (paths)
	{
		new = ft_queuenew(paths->content, paths->content_size, paths->id);
		new->next = copy_path(paths->next);
		return (new);
	}
	return (NULL);
}

t_combinations	*new_set(t_queue *paths)
{
	t_queue *base;
	t_queue *temp_new;
	t_combinations *new;

	base = paths;
	if (!(new = (t_combinations *)malloc(sizeof(t_combinations) + 1)))
		ft_errno();
	new->set = copy_path(paths);
	temp_new = new->set;
	while (base)
	{
		if (!are_duplicates(temp_new, base->parralel))
		{
			temp_new->parralel = copy_path(base->parralel);
			temp_new = temp_new->parralel;
		}
		base = base->parralel;
	}
	return (new);
}

void	combinations(t_farm *farm)
{
	int				size;
	t_combinations	*temp;
	t_queue			*path;

	size = size_of_set(farm->paths);
	temp = farm->paths;
	path = temp->set;
	while (path->parralel)
	{
		temp->next = new_set(path);
		temp = temp->next;
		path = path->parralel;
	}
}
