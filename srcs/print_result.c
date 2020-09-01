/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 22:32:36 by gtorvald          #+#    #+#             */
/*   Updated: 2020/08/11 22:32:40 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		end_finish(int index, int *paths_of_ants, int *next_room, int end)
{
	if (paths_of_ants[index] == end)
		return (-2);
	else if (paths_of_ants[index] != -2)
		return (next_room[paths_of_ants[index]]);
	return (paths_of_ants[index]);
}

void	get_next_room(t_lemin *info, int **paths_of_ants, int *next_room,
t_paths *paths)
{
	int		start;
	int		end;
	int		i;
	t_paths	*help;

	start = num_room(info, info->start->name);
	end = num_room(info, info->end->name);
	i = 0;
	while (i < info->aunt->c)
	{
		if ((*paths_of_ants)[i] == -1)
		{
			help = paths;
			while (help && help->ants && i++ < info->aunt->c)
			{
				(*paths_of_ants)[i - 1] = help->path[1];
				help->ants--;
				help = help->next;
			}
			break ;
		}
		else
			(*paths_of_ants)[i] = end_finish(i, *paths_of_ants, next_room, end);
		i++;
	}
}

int		*get_array_next_rooms(t_paths *paths, int count_rooms)
{
	t_paths *help;
	int		*next_room;
	int		i;

	next_room = malloc(sizeof(int) * count_rooms);
	help = paths;
	next_room[help->path[help->len - 1]] = -1;
	next_room[help->path[0]] = -1;
	while (help)
	{
		i = 1;
		while (i < help->len - 1)
		{
			next_room[help->path[i]] = help->path[i + 1];
			i++;
		}
		help = help->next;
	}
	return (next_room);
}

int		print_step(t_lemin *info, int *paths_of_ants)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i++ < info->aunt->c)
		if (paths_of_ants[i - 1] > -1)
		{
			flag = 1;
			ft_printf("L%d-%s ", i, name_room(info, paths_of_ants[i - 1]));
		}
	if (flag)
		ft_printf("\n");
	i = 0;
	flag = 1;
	while (i++ < info->aunt->c)
		if (paths_of_ants[i - 1] != -2)
		{
			flag = 0;
			break ;
		}
	return (flag);
}

void	print_result(t_lemin *info, t_paths *paths, int start)
{
	int		*paths_of_ants;
	int		*next_room;
	int		i;
	bool	flag;
	int		end;

	end = num_room(info, info->end->name);
	paths_of_ants = malloc(sizeof(int) * info->aunt->c);
	i = 0;
	while (i++ < info->aunt->c)
		paths_of_ants[i - 1] = -1;
	next_room = get_array_next_rooms(paths, info->count_rooms);
	while (1)
	{
		get_next_room(info, &paths_of_ants, next_room, paths);
		if ((flag = print_step(info, paths_of_ants)) == 1)
			break ;
	}
	free(paths_of_ants);
	free(next_room);
}
