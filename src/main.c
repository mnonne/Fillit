/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:13:17 by aminadzh          #+#    #+#             */
/*   Updated: 2017/12/21 17:54:28 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	***f_content;
	t_list	*lst;
	t_map	*map;

	if (ac != 2)
	{
		ft_putendl_fd("usage: fillit [filename]", 2);
		return (1);
	}
	if (!(f_content = file_open(av[1])))
	{
		ft_putendl("error");
		return (1);
	}
	lst = create_lst(f_content);
	map = solve(lst);
	print_map(map);
	return (0);
}

void	print_map(t_map *map)
{
	char	**tetris;
	int		i;

	tetris = map->arr;
	i = 0;
	while (tetris[i])
	{
		ft_putendl(tetris[i]);
		i++;
	}
}
