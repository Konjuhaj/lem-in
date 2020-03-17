/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:17:53 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/30 17:32:14 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	int		remember;

	i = -1;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (++i < len && haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			remember = i;
			while (haystack[i] == needle[j] && i < len)
			{
				if (needle[j + 1] == '\0')
					return ((char *)haystack + remember);
				i++;
				j++;
			}
			j = 0;
			i = remember;
		}
	}
	return (NULL);
}
