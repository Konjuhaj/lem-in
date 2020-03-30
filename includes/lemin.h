/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 19:14:59 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/30 20:41:28 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN
# include "../libraries/ft_printf/includes/ft_printf.h"

typedef struct	s_room
{
	void		**pipe;
	int			visited;
	int			length;
	char		*name;
}				t_room;


typedef struct	s_farm
{
	t_room		**rooms;
	t_room		*source;
	t_room		*sink;
	int			ants;
}				t_farm;


void			ft_errno(void);

#endif
