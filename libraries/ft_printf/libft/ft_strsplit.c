/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:01:10 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/31 09:57:35 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**splt;
	int		i;
	int		w;

	i = -1;
	w = 0;
	if (!s || (!(splt = (char **)malloc(sizeof(char *) *
	(ft_wcount(s, c) + 1)))))
		return (NULL);
	while (++i < (int)ft_strlen(s))
	{
		if ((i == 0 && s[i] != c) || ((s[i - 1] == c) && s[i] != c))
		{
			if (!(splt[w] = (char *)malloc(sizeof(char) *
			(ft_wlen(s + i, c) + 1))))
				return (NULL);
			ft_strncpy(splt[w], s + i, ft_wlen(s + i, c));
			splt[w][ft_wlen(s + i, c)] = '\0';
			w++;
		}
	}
	splt[w] = NULL;
	return (splt);
}
