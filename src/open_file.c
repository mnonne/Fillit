/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:25:53 by aminadzh          #+#    #+#             */
/*   Updated: 2018/01/03 16:08:04 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Opens a file for reading. If file is valid returns array
*/

char	***file_open(char *filename)
{
	int		fd;
	int		ret;
	char	*buf;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (NULL);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (close(fd) == -1)
		return (NULL);
	return (val_file(buf));
}

/*
** A main function in validating the file. If valid return an array
*/

char	***val_file(char *s)
{
	char	***tab;
	char	**tet;
	int		i;

	if (!(valid_sym(s)))
		return (NULL);
	if (!(tab = (char ***)malloc(sizeof(tab) * (count_tets(s) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (!(tet = tet_new(s)))
			return (NULL);
		tab[i] = tet;
		i++;
		s = s + 20;
		if (*s == '\n')
			s++;
	}
	tab[i] = NULL;
	return (tab);
}

/*
** Counts the amount of figures in file
*/

int		count_tets(char *s)
{
	int		i;

	i = 0;
	while (*s)
	{
		i++;
		s += 19;
		if (*s == '\n')
			s += 2;
	}
	return (i);
}

/*
** Creates and returns a tetrimino structure
*/

t_tet	*create_tetrimino(char **tet, char let)
{
	t_tet	*tetrimino;

	tetrimino = (t_tet *)ft_memalloc(sizeof(t_tet));
	tetrimino->points = create_matrix(tet);
	tetrimino->let = let;
	return (tetrimino);
}
