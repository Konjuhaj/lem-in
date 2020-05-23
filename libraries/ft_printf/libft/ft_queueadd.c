/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queueadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 18:20:33 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/05/23 20:13:09 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_queueadd(t_queue **alst, t_queue *new, char *caller)
{
	t_queue *temp;

	temp = *alst;
	while(temp->next)
		temp = temp->next;
	temp->next = new;
	new->called_by = caller;
}
