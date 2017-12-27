/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:24:40 by aminadzh          #+#    #+#             */
/*   Updated: 2017/12/21 18:24:12 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../libft/libft.h"

# define BUFF_SIZE 4096

typedef struct	s_p
{
	int		x;
	int		y;
}				t_p;

typedef struct	s_map
{
	char	**arr;
	int		m_size;
}				t_map;

typedef struct	s_tet
{
	t_p		*points;
	char	let;
}				t_tet;

char	***file_open(char *filename);
char	***val_file(char *s);
int		count_tets(char *s);
char	**tet_new(char *s);
int		valid_sym(char *s);
int		last_n(char *s);
int		valid_sym_count(char **tet);
int		valid_tet(char **tet);
t_p		*create_matrix(char **tet);
t_list	*create_lst(char ***tet);
void	trim_matrix(t_p *mat);
int		count_map_size(t_list *lst);
t_map	*solve(t_list *lst);
t_map	*new_map(int size);
void	free_map(t_map *map);
int		place_tet(t_map *map, t_p pos, t_list *lst);
void	del_tet(t_map *map, t_p pos, t_list *lst, int to_del);
void	print_map(t_map *map);
t_tet   *create_tetrimino(char **tet, char let);
t_list  *lst_nu(char **tet, size_t content_size, char let);

#endif
