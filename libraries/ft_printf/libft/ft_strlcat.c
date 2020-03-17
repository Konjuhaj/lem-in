/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:10:52 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/24 13:35:14 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t result;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	if (dstsize < i)
		result = j + dstsize;
	else
		result = j + i;
	j = 0;
	while (src[j] && i + 1 < dstsize)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (result);
}
