/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_managment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 17:25:28 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/06/16 17:57:03 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

// static void		print_queue_id(t_queue *queue)
// {
// 	t_queue *temp;

// 	temp = queue;
// 	while (temp)
// 	{
// 		ft_printf("%s -> ", temp->id);
// 		temp = temp->next;
// 	}
// 	ft_putstr("\n");
// }

void	mm_store_paths(t_farm *farm, t_queue *path)
{
	static t_queue_set	*set;
	t_queue_set			*base;

	set = (t_queue_set *)malloc(sizeof(t_queue_set));
	if (farm != NULL)
		farm->paths->set = set;
	base = set;
	while (base->next)
		base = base->next;
	base->next = (t_queue_set *)malloc(sizeof(t_queue_set));
	base = base->next;
	base->queue = path;
}
