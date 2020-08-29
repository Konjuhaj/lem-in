/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:17:35 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/08/25 14:21:37 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int	is_command_or_comment(char *s)
{
	if (s[0] == '#' && s[1] != '#')
		return (1);
	else if (s[0] == '#' && s[1] == '#' &&
			!ft_strequ(s, "##start") && !ft_strequ(s, "##end"))
		return (1);
	return (0);
}
