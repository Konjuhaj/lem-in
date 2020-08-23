/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:38:36 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/23 20:29:11 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		print_queue_id(t_queue *queue)
{
	t_queue *temp;

	temp = queue;
	while (temp)
	{
		ft_printf("%s(%s) -> ", temp->id, temp->called_by);
		temp = temp->next;
	}
	ft_putstr("\n");
}

void		print_queue_id_rev(t_queue *queue)
{
	t_queue *temp;

	temp = queue->previous;
	ft_printf("FIST %s(%p)\n ", queue->id, queue->content);
	while (!ft_strequ(temp->id, queue->id))
	{
		ft_printf("%s(%p) -> ", temp->id, temp->content);
		temp = temp->previous;
	}
	ft_printf("%s(%p) -> ", temp->id, temp->content);
	ft_putstr("\n");
}

void		print_set(t_combinations *set)
{
	t_queue *test;
	test = set->set;
	ft_printf("\nSET Lines required: %d\n", set->print);
	while (test)
	{
		ft_printf("A: %d, D %d \n", test->ants, test->distance);
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
		ft_printf("\nSET-%d\n", i++);
		print_set(temp);
		temp = temp->next;
	}
}

