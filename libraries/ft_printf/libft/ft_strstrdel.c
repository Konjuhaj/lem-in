/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:29:09 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/09 17:11:56 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strstrdel(char ***s)
{
	int		i;
	char	**temp;

	i = -1;
	temp = *s;
	while (temp[++i])
	{
		free((void *)temp[i]);
		temp[i] = NULL;
	}
	free((void*)*s);
}
