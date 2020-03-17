/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:14:59 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/28 18:35:49 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *ptr;

	temp = *alst;
	while (temp)
	{
		ptr = temp;
		ft_lstdelone(&temp, del);
		temp = ptr->next;
	}
	*alst = NULL;
}
