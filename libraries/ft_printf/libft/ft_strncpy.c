/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:15:21 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/24 14:36:38 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t i;

	i = -1;
	if (dest == src || len <= 0)
		return (dest);
	while (++i < len && src[i])
		dest[i] = src[i];
	while (i < len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
