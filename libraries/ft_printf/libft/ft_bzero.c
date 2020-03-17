/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:13:54 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/30 16:47:44 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = -1;
	ptr = (unsigned char *)str;
	while (++i < len)
		ptr[i] = '\0';
}
