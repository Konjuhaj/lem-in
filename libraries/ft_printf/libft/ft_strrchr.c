/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:17:53 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/27 12:42:17 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *haystack, int c)
{
	int i;

	i = ft_strlen(haystack);
	if (c == '\0')
		return ((char *)haystack + ft_strlen(haystack));
	while (0 <= --i)
	{
		if (haystack[i] == c)
			return ((char *)haystack + i);
	}
	return (NULL);
}
