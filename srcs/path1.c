/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:59:34 by gtorvald          #+#    #+#             */
/*   Updated: 2020/08/11 21:59:37 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	initialization(bool **this_lvl, bool **next_lvl, int **prev_room,
t_lemin *info)
{
	int i;

	(*this_lvl) = malloc(sizeof(bool) * info->count_rooms);
	zeroing_bool(this_lvl, info->count_rooms);
	(*next_lvl) = malloc(sizeof(bool) * info->count_rooms);
	zeroing_bool(next_lvl, info->count_rooms);
	(*prev_room) = malloc(sizeof(int) * info->count_rooms);
	i = 0;
	while (i < info->count_rooms)
		(*prev_room)[i++] = -1;
	(*this_lvl)[num_room(info, info->start->name)] = 1;
}

bool	searching_path(bool *this_lvl, bool *next_lvl, int **prev_room,
t_lemin *info)
{
	int		i;
	int		j;
	bool	flag;

	flag = 0;
	while (!flag && check_this(this_lvl, info->count_rooms))
	{
		i = 0;
		while (!flag && i++ < info->count_rooms)
			if (this_lvl[i - 1])
			{
				j = 0;
				while (!flag && j++ < info->count_rooms)
					if (!info->copy[j - 1] && info->table[i - 1][j - 1])
					{
						(*prev_room)[j - 1] = i - 1;
						info->copy[j - 1] = 1;
						if (j - 1 == num_room(info, info->end->name))
							flag = 1;
						next_lvl[j - 1] = 1;
					}
			}
		swap_and_zeroing(&this_lvl, &next_lvl, info->count_rooms);
	}
	return (flag);
}

int		*get_array_prev_rooms(t_lemin *info)
{
	bool	*this_lvl;
	bool	*next_lvl;
	int		*prev_room;
	bool	flag;

	initialization(&this_lvl, &next_lvl, &prev_room, info);
	info->copy[num_room(info, info->start->name)] = 1;
	flag = searching_path(this_lvl, next_lvl, &prev_room, info);
	free(this_lvl);
	free(next_lvl);
	if (!flag)
	{
		free(prev_room);
		return (NULL);
	}
	return (prev_room);
}
