/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:51:09 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/05/23 18:26:43 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		find_paths(t_room **room, t_room **sink)
{
	t_list	*queue;
	t_room	*temp;
	int		i;

	queue = ft_lstnew(room, sizeof(*room));
	temp = *room;
	while (temp != *sink)
	{
		i = -1;
		while (temp->pipe[++i] != NULL)
		{
			ft_queueadd(&queue, ft_lstnew(temp->pipe[i], sizeof(*room)));
		}
	}
}
