/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuntik <phuntik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:03:27 by phuntik           #+#    #+#             */
/*   Updated: 2020/08/09 00:07:56 by phuntik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

bool			handle_err(char *str, t_lemin **lem, char ***split, char **line)
{
	ft_putstr("ERROR: ");
	ft_putendl(str);
	free_lemin(lem, 0);
	if (split)
		ft_free_arr(split);
	if (line)
		free(*line);
	exit(EXIT_FAILURE);
}

int				num_chr(char *line, char c)
{
	int			i;
	int			n;

	i = 0;
	n = 0;
	while (line[i] != '\0')
	{
		if (line[i] == c)
			n++;
		i++;
	}
	return (n);
}

void			add_str_to_map(t_lemin **lem, char *line)
{
	t_map	*help;

	if ((*lem)->map == NULL)
	{
		(*lem)->map = (t_map *)malloc(sizeof(t_map));
		(*lem)->map->line = ft_strdup(line);
		(*lem)->map->next = NULL;
		return ;
	}
	help = (*lem)->map;
	while (help->next)
		help = help->next;
	help->next = (t_map *)malloc(sizeof(t_map));
	help->next->line = ft_strdup(line);
	help->next->next = NULL;
}

void			free_map(t_map **map)
{
	t_map *help;
	t_map *head;

	head = *map;
	help = (*map)->next;
	while (help)
	{
		free(head->line);
		free(head);
		head = help;
		help = help->next;
	}
	free(head->line);
	free(head);
}

void			print_map(t_map *map)
{
	t_map	*help;

	help = map;
	while (help)
	{
		ft_printf("%s\n", help->line);
		help = help->next;
	}
	ft_printf("\n");
}
