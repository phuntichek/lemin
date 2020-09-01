/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 21:13:37 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/09 03:43:30 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

bool			write_start_room(t_lemin **lem)
{
	char		**split;
	char		*line;

	if ((*lem)->start->name != NULL)
		handle_err("double start", lem, 0, 0);
	if (!(get_next_line((*lem)->fd, &line)))
		handle_err("invalid read start room", lem, 0, &line);
	if (!line)
		handle_err("invalid read start room 2", lem, 0, &line);
	add_str_to_map(lem, line);
	if (line[0] == '#')
		handle_err("invalid start room", lem, 0, &line);
	split = ft_strsplit(line, ' ');
	if (split[0][0] == 'L')
		handle_err("name room with L", lem, &split, &line);
	if (!check_dublicate(lem, &line))
		handle_err("found duplicate of start room", lem, &split, &line);
	if (!((*lem)->start->name = ft_strdup(split[0])))
		handle_err("cant write name of start room", lem, &split, &line);
	(*lem)->start->x = ft_atoi(split[1]);
	(*lem)->start->y = ft_atoi(split[2]);
	ft_free_arr(&split);
	free(line);
	return (true);
}

bool			write_end_room(t_lemin **lem)
{
	char		**split;
	char		*line;

	if ((*lem)->end->name != NULL)
		handle_err("double end", lem, 0, 0);
	if (!(get_next_line((*lem)->fd, &line)))
		handle_err("invalid read end room", lem, 0, &line);
	if (!line)
		handle_err("invalid read end room 2", lem, 0, &line);
	add_str_to_map(lem, line);
	if (line[0] == '#')
		handle_err("invalid end room", lem, 0, &line);
	split = ft_strsplit(line, ' ');
	if (split[0][0] == 'L')
		handle_err("name room with L", lem, &split, &line);
	if (!check_dublicate(lem, &line))
		handle_err("found duplicate of end room", lem, &split, &line);
	if (!((*lem)->end->name = ft_strdup(split[0])))
		handle_err("cant write name of end room", lem, &split, &line);
	(*lem)->end->x = ft_atoi(split[1]);
	(*lem)->end->y = ft_atoi(split[2]);
	ft_free_arr(&split);
	free(line);
	return (true);
}

bool			write_room(t_lemin **lem, char **line)
{
	char		**split;

	if (*line)
		split = ft_strsplit(*line, ' ');
	if (split[0][0] == 'L')
		handle_err("name room with L", lem, &split, line);
	if ((*lem)->head->first_room == NULL)
		(*lem)->head->first_room = (*lem)->room;
	if (!check_dublicate(lem, line))
		handle_err("found duplicate", lem, &split, line);
	if (!((*lem)->room->name = ft_strdup(split[0])))
		handle_err("cant write name", lem, &split, line);
	(*lem)->room->x = ft_atoi(split[1]);
	(*lem)->room->y = ft_atoi(split[2]);
	(*lem)->room->next = NULL;
	ft_free_arr(&split);
	return (true);
}

void			while_check_doublicate(t_lemin **lem, char **line)
{
	t_room		*help;
	char		**split;

	help = (*lem)->head->first_room;
	split = ft_strsplit(*line, ' ');
	while (help != NULL)
	{
		if (help->name != NULL)
		{
			if (ft_strequ(split[0], help->name))
				handle_err("duplicate: doble name", lem, &split, 0);
			if (ft_atoi(split[1]) == help->x && ft_atoi(split[2]) == help->y)
				handle_err("duplicate: double coordinates", lem, &split, 0);
		}
		if ((*lem)->start->name && ft_atoi(split[1]) == (*lem)->start->x
		&& ft_atoi(split[2]) == (*lem)->start->y)
			handle_err("duplicate: double coordinates", lem, &split, 0);
		if ((*lem)->end->name && ft_atoi(split[1]) == (*lem)->end->x &&
		ft_atoi(split[2]) == (*lem)->end->y)
			handle_err("duplicate: double coordinates", lem, &split, 0);
		help = help->next;
	}
	ft_free_arr(&split);
}

bool			check_dublicate(t_lemin **lem, char **line)
{
	t_room		*help;

	help = (*lem)->head->first_room;
	if ((*lem)->count_rooms == 0)
		return (true);
	while_check_doublicate(lem, line);
	return (true);
}
