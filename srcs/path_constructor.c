/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_constructor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 20:02:28 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/06/11 21:08:58 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void		print_queue_id(t_queue *queue)
{
	t_queue *temp;

	temp = queue;
	while (temp)
	{
		ft_printf("%s -> ", temp->id);
		temp = temp->next;
	}
	ft_putstr("\n");
}

void	path_constructor(t_farm *farm, t_queue *path)
{
	static t_combinations *paths;
	static int i;

	if (farm != NULL)
	{
		paths = (t_combinations**)malloc(sizeof(t_combinations*));
		paths->paths = (t_queue **)malloc(sizeof(t_queue *) * 300);
		farm->paths = paths;
	}
	else
	{
		paths->paths[i] = path;
		print_queue_id(paths->paths[i]);
		i++;
	}
}
