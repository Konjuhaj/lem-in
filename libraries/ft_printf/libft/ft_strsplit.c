/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:01:10 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/07/10 15:03:26 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**splt;
	int		w_len;
	int		len;
	int		i;
	int		w;

	i = -1;
	w = 0;
	len = ft_strlen(s);
	if (!s || (!(splt = (char **)malloc(sizeof(char *) *
	(ft_wcount(s, c) + 1)))))
		return (NULL);
	while (++i < len)
	{
		if ((i == 0 && s[i] != c) || ((s[i - 1] == c) && s[i] != c))
		{
			w_len = ft_wlen(s + i, c);
			if (!(splt[w] = (char *)malloc(sizeof(char) * (w_len + 1))))
				return (NULL);
			ft_strncpy(splt[w], s + i, w_len);
			splt[w++][w_len] = '\0';
		}
	}
	splt[w] = NULL;
	return (splt);
}
