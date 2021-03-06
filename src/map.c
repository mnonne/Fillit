/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:06:52 by aminadzh          #+#    #+#             */
/*   Updated: 2018/01/03 16:05:05 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Creates and returns the map
*/

t_map	*new_map(int size)
{
	t_map	*map;
	int		i;

	i = 0;
	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->m_size = size;
	map->arr = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		map->arr[i] = ft_strnew(size);
		ft_memset(map->arr[i], '.', size);
		i++;
	}
	map->arr[i] = NULL;
	return (map);
}

/*
** Deletes a map
*/

void	free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->m_size)
	{
		ft_memdel((void **)&map->arr[i]);
		i++;
	}
	ft_memdel((void **)&map->arr);
	ft_memdel((void **)&map);
}

/*
** Pleaces a figure to pos (x, y) and returns 0 in case of success
** If placement is not successfull, returns a number of pleaced points.
** Result is used in deleting figure
*/

int		place_tet(t_map *map, t_p pos, t_list *lst)
{
	t_p		*points;
	int		i;

	points = ((t_tet *)lst->content)->points;
	i = 1;
	while (i < 5)
	{
		if ((pos.y + points[i - 1].y < map->m_size) && (pos.x + points[i - 1].x
					< map->m_size) && ((map->arr[pos.y + points[i - 1].y]
							[pos.x + points[i - 1].x]) == '.'))
		{
			(map->arr[pos.y + points[i - 1].y][pos.x + points[i - 1].x]) =
				((t_tet *)lst->content)->let;
			i++;
		}
		else
			return (i);
	}
	return (0);
}

/*
** Deletes a figure, if pleacement was not successfull
*/

void	del_tet(t_map *map, t_p pos, t_list *lst, int to_del)
{
	t_p		*points;
	int		i;

	points = ((t_tet *)lst->content)->points;
	i = 0;
	while (i < (to_del - 1))
	{
		(map->arr[pos.y + points[i].y][pos.x + points[i].x]) = '.';
		i++;
	}
}
