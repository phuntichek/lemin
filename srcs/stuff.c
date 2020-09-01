/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:59:44 by gtorvald          #+#    #+#             */
/*   Updated: 2020/08/11 21:59:46 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*name_room(t_lemin *info, int index)
{
	int		i;
	t_room	*ptr_room;

	ptr_room = info->room;
	i = 0;
	while (i++ < index)
		ptr_room = ptr_room->next;
	return (ptr_room->name);
}

int		num_room(t_lemin *info, char *name)
{
	int		i;
	t_room	*ptr_room;

	i = 0;
	ptr_room = info->room;
	while (ft_strcmp(ptr_room->name, name))
	{
		ptr_room = ptr_room->next;
		i++;
	}
	return (i);
}

void	zeroing_bool(bool **stats, int count_rooms)
{
	int		i;

	i = 0;
	while (i < count_rooms)
		(*stats)[i++] = 0;
}

void	swap_and_zeroing(bool **this_lvl, bool **next_lvl, int count_rooms)
{
	bool	*help;

	help = *this_lvl;
	*this_lvl = *next_lvl;
	*next_lvl = help;
	zeroing_bool(next_lvl, count_rooms);
}

bool	check_this(bool *this_lvl, int count_rooms)
{
	int i;

	i = 0;
	while (i < count_rooms)
		if (this_lvl[i++])
			return (1);
	return (0);
}
