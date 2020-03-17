/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 08:36:09 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/26 17:01:58 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*s2;

	start = 0;
	if (!s)
		return (NULL);
	end = ft_strlen(s);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (s[start] == '\0')
		return ("");
	while (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
		end--;
	if (start == end || end < start)
		return (ft_strnew(1));
	s2 = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!s2)
		return (NULL);
	ft_strncpy(s2, s + start, end - start);
	s2[end - start] = '\0';
	return (s2);
}
