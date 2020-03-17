/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:31:23 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/26 13:47:37 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *dest;

	if (!(dest = (char *)malloc(size + 1)))
		return (NULL);
	ft_memset(dest, '\0', size + 1);
	return (dest);
}
