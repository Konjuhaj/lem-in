/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 07:10:04 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/26 15:04:30 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = -1;
	if (s1 == NULL && s2 == NULL)
		return (1);
	else if (s1 == NULL || s1 == NULL)
		return (0);
	while (s1[++i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}
