/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queueadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 18:20:33 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/05/23 18:23:43 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_queueadd(t_list **alst, t_list *new)
{
	t_list *temp;

	temp = *alst;
	while(temp->next)
		temp = temp->next;
	temp->next = new;
}
