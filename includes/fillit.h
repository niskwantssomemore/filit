/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:18:09 by sazalee           #+#    #+#             */
/*   Updated: 2019/08/05 16:46:20 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 4096

int g_tetrinumber;

typedef struct	s_tetris
{
	char			**tetrimino;
	char			alphabet;
	int				x;
	int				y;
	struct s_tetris	*next;
}				t_tetris;

void			ft_error(void);
int				counter_of_tetriminos(char *buf);
int				format(char *buf);
char			**fillbase(char **base, char *buf);
char			**ft_read(char *av);
int				ft_check_c(char *str, int i);
int				ft_check_l(char *str);
int				ft_check_s(char *str);
int				check(char **tetriminos);
int				ft_height_c(char *str);
int				ft_width_c(char *str);
int				ft_neighbors_c(char *str, int height, int width);
int				ft_index_plus_one(char *str, int index, int counter, int flag);
int				ft_index_minus_one(char *str, int index, int counter, int flag);
int				ft_index_plus_five(char *str, int index, int counter, int flag);
int				ft_index_minu_five(char *str, int index, int counter, int flag);
int				threeinarow(char *str, int index, int counter, int flag);
t_tetris		*createtri(char **tetrimino, int numord);
t_tetris		*addtetri(char **base);

#endif
