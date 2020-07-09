/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:38:36 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/09 11:21:30 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		print_queue_id(t_queue *queue)
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

void		print_set(t_combinations *set)
{
	//testing
	t_queue *test;
	test = set->set;
	while (test)
	{
		print_queue_id(test);
		test = test->parralel;
	}
	ft_printf("\n");
}

void		print_sets(t_combinations *set)
{
	t_combinations	*temp;
	int				i;

	temp = set;
	i = 0;
	while (temp)
	{
		ft_printf("\nSET %d\n", i++);
		print_set(temp);
		temp = temp->next;
	}
}

