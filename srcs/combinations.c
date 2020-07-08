/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:46:41 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/08 15:56:49 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

/*
** Might work without temp variables
**
*/

static int	check_for_duplicates(t_queue *path1, t_queue *path2)
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
			if (ft_strequ(temp2->id, base1->id) == 1)
				return (0);
			temp2 = temp2->next;
		}
		base1 = base1 ->next;
	}
	return (1);
}

void	combinations(t_farm *farm)
{

}
