/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tlemin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 22:11:11 by gtorvald          #+#    #+#             */
/*   Updated: 2020/08/11 22:11:13 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	free_room(t_room **rooms)
{
	t_room *help;
	t_room *head;

	head = *rooms;
	help = (*rooms)->next;
	while (help)
	{
		free(head->name);
		free(head);
		head = help;
		help = help->next;
	}
	free(head->name);
	free(head);
}

void	free_links(t_link **link)
{
	t_link *head;
	t_link *help;

	head = *link;
	help = (*link)->next;
	while (help)
	{
		free(head->room1);
		free(head->room2);
		free(head);
		head = help;
		help = help->next;
	}
	if (head->room1)
		free(head->room1);
	if (head->room2)
		free(head->room2);
	free(head);
}

void	free_table(bool **table, int count_rooms)
{
	int i;

	i = 0;
	while (i < count_rooms)
	{
		free(table[i]);
		i++;
	}
	free(table);
}

void	free_paths(t_paths **paths)
{
	t_paths *help;
	t_paths *head;

	head = *paths;
	help = (*paths)->next;
	while (help)
	{
		free(head->path);
		free(head);
		head = help;
		help = help->next;
	}
	free(head->path);
	free(head);
}

void	free_lemin(t_lemin **info, t_paths **paths)
{
	if ((*info)->head->first_room)
		free_room(&((*info)->head->first_room));
	if ((*info)->head->first_link)
		free_links(&((*info)->head->first_link));
	free((*info)->start->name);
	free((*info)->start);
	free((*info)->end->name);
	free((*info)->end);
	free((*info)->head);
	free((*info)->aunt);
	if ((*info)->table)
		free_table((*info)->table, (*info)->count_rooms);
	if ((*info)->statuses)
		free((*info)->statuses);
	if ((*info)->map)
		free_map(&((*info)->map));
	free(*info);
	if (paths)
		free_paths(paths);
}
