/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:36:30 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/10 16:58:05 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		get_count_rooms(t_lemin *info)
{
	t_room	*room;
	int		count;

	room = info->room;
	count = 0;
	while (room)
	{
		count++;
		room = room->next;
	}
	return (count);
}

t_lemin	*build_info(int argc, char **argv)
{
	t_lemin		*info;

	info = (t_lemin *)malloc(sizeof(t_lemin));
	init_lem(info);
	if (argc > 1)
	{
		if ((info->fd = open(argv[1], O_RDONLY)) == -1)
			handle_err("not valid file", &info, 0, 0);
	}
	else
		info->fd = 0;
	parser(&info);
	info->count_rooms = get_count_rooms(info);
	return (info);
}

void	distribution_of_ants(t_lemin *info, t_paths *paths)
{
	t_paths	*ptr;
	t_paths	*right_path;
	int		c;
	int		min_sum;

	c = info->aunt->c;
	while (c)
	{
		ptr = paths;
		min_sum = MAX_INT;
		while (ptr)
		{
			if (ptr->len + ptr->ants < min_sum)
			{
				min_sum = ptr->len + ptr->ants;
				right_path = ptr;
			}
			ptr = ptr->next;
		}
		right_path->ants++;
		c--;
	}
}

int		get_count_paths(t_paths *paths)
{
	t_paths	*help;
	int		count;

	count = 0;
	help = paths;
	while (help)
	{
		count++;
		help = help->next;
	}
	return (count);
}

int		main(int argc, char **argv)
{
	t_lemin	*info;
	t_paths	*paths;

	info = build_info(argc, argv);
	if ((paths = get_all_paths(info)) == NULL)
	{
		ft_printf("ERROR: no path\n");
		free_lemin(&info, 0);
		return (1);
	}
	info->count_paths = get_count_paths(paths);
	distribution_of_ants(info, paths);
	paths = paths;
	print_map(info->map);
	print_result(info, paths, num_room(info, info->start->name));
	free_lemin(&info, &paths);
	return (0);
}
