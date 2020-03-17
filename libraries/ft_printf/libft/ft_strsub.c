/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 07:29:18 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/26 17:32:31 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	i = 0;
	if (!s || !(s2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(s2, s + start, len);
	s2[len] = '\0';
	return (s2);
}
