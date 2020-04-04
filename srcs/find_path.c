/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 17:51:09 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/04/04 19:31:36 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		find_paths(t_room **room, t_room **sink, int limit, int current)
{
	int i;
	t_room *base;

	i = 0;
	if (limit == 6)
		ft_errno();
	if (limit == current)
		return (1);
	while (*room != *sink)
	{
		(*room)->visited = 1;
		ft_printf("visited %s\n", (*room)->name);
		while ((*room)->pipe[i])
		{
			base = (*room)->pipe[i];
			while (base->visited == 1 && (*room)->pipe[i + 1])
				base = (*room)->pipe[++i];
			if (!base)
				break;
			ft_printf("next one %s\n", base->name);
			if (find_paths(&base, sink, limit, current + 1) == 1)
				break;
			i++;
		}
		return (2);
	}
	ft_printf("FOUND IT!!\n");
	return (3);
}
