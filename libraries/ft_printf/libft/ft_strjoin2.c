/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 09:55:29 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/09 10:35:56 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char const *s1, char const *s2, char const *s3)
{
	char	*s4;
	int		len;
	int		i;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	s4 = (char *)malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1));
	if (!s4)
		return (NULL);
	ft_strcpy(s4, s1);
	while (s2[++i])
		s4[len++] = s2[i];
	i = -1;
	while (s3[++i])
		s4[len++] = s3[i];
	s4[len] = '\0';
	return (s4);
}
