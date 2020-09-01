/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:59:04 by gtorvald          #+#    #+#             */
/*   Updated: 2020/08/11 21:59:17 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

bool	**get_table_of_links(t_lemin *info)
{
	bool	**table;
	t_link	*links;
	int		i;
	int		j;

	table = malloc(info->count_rooms * sizeof(bool*));
	i = 0;
	while (i < info->count_rooms)
		table[i++] = malloc(info->count_rooms * sizeof(bool));
	i = 0;
	while (i < info->count_rooms)
	{
		j = 0;
		while (j < info->count_rooms)
			table[i][j++] = 0;
		i++;
	}
	links = info->link;
	while (links)
	{
		table[num_room(info, links->room1)][num_room(info, links->room2)] = 1;
		table[num_room(info, links->room2)][num_room(info, links->room1)] = 1;
		links = links->next;
	}
	return (table);
}

t_paths	*get_path(t_lemin *info, int **prev_room, int start, int len)
{
	int		i;
	int		j;
	t_paths *path;

	i = num_room(info, info->end->name);
	while (i != start)
	{
		len++;
		i = (*prev_room)[i];
	}
	path = malloc(sizeof(t_paths));
	path->len = len;
	path->ants = 0;
	path->path = malloc(sizeof(int) * len);
	i = len - 2;
	j = num_room(info, info->end->name);
	path->path[len - 1] = j;
	while (i >= 0)
	{
		path->path[i--] = (*prev_room)[j];
		j = (*prev_room)[j];
	}
	free(*prev_room);
	return (path);
}

t_paths	*search_paths(t_lemin *info)
{
	int		*prev_room;
	int		i;

	info->copy = malloc(sizeof(bool) * info->count_rooms);
	i = 0;
	while (i < info->count_rooms)
	{
		info->copy[i] = info->statuses[i];
		i++;
	}
	if ((prev_room = get_array_prev_rooms(info)) == NULL)
	{
		free(info->copy);
		return (NULL);
	}
	free(info->copy);
	return (get_path(info, &prev_room, num_room(info, info->start->name), 1));
}

void	update_status(t_paths *path, t_lemin *info)
{
	int i;
	int	num_end;

	num_end = num_room(info, info->end->name);
	i = 0;
	while (i < path->len)
	{
		if (path->path[i] != num_end)
			info->statuses[path->path[i]] = 1;
		i++;
	}
}

t_paths	*get_all_paths(t_lemin *info)
{
	t_paths *paths;
	t_paths	*head_paths;

	info->table = get_table_of_links(info);
	info->statuses = malloc(sizeof(bool) * info->count_rooms);
	zeroing_bool(&info->statuses, info->count_rooms);
	if ((paths = search_paths(info)) == NULL)
		return (NULL);
	head_paths = paths;
	update_status(paths, info);
	while ((paths->next = search_paths(info)) != NULL)
	{
		update_status(paths->next, info);
		paths = paths->next;
	}
	return (head_paths);
}
