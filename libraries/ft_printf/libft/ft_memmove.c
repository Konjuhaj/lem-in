/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:24:55 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/26 15:38:56 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;
	size_t			i;

	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (ptr > ptr2)
	{
		while (++i <= n)
			ptr[n - i] = ptr2[n - i];
	}
	else
	{
		i = -1;
		while (++i < n)
			ptr[i] = ptr2[i];
	}
	return (dst);
}
