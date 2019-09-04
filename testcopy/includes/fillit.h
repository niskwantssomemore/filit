/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:18:09 by sazalee           #+#    #+#             */
/*   Updated: 2019/09/04 16:49:10 by sazalee          ###   ########.fr       */
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
# include "../libft/libft.h"
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

int				xmin(char **field);
char			**left(int xmin, char **field);
int				ymin(char **field);
char			**up(int ymin, char **field);
t_tetris		*leftup(t_tetris *begin);
int				read_check_checker(int c, char *v, char **b, t_tetris **beg);
int				ft_check_c(char *str, int i);
int				ft_check_l(char *str);
int				ft_check_s(char *str);
int				check(char **tetriminos);
int				ft_height_c(char *str);
int				ft_width_c(char *str);
int				ft_neighbors_c(char *str, int height, int width);
void			ft_structfree(t_tetris *tmp);
void			ft_error(void);
void			ft_freetime(char **base, int counter);
void			result_of_project(char **finalb, int finalsize);
int				ft_index_plus_one(char *str, int index, int counter, int flag);
int				ft_index_minus_one(char *str, int index, int counter, int flag);
int				ft_index_plus_five(char *str, int index, int counter, int flag);
int				ft_index_minu_five(char *str, int index, int counter, int flag);
int				threeinarow(char *str, int index, int counter, int flag);
int				counter_of_tetriminos(char *buf);
int				format(char *buf);
char			**fillbase(char **base, char *buf);
char			**ft_read(char *av);
int				tester(t_tetris *begin, char **finalbase, int finalsize);
char			**adder(t_tetris *begin, char **finalbase);
char			**cleaner(t_tetris *begin, char **finalb);
int				finder(t_tetris *begin, int finalsize, char **finalb);
void			solve(t_tetris *begin, int finalsize, char **finalb);
t_tetris		*createtri(char **tetrimino, int numord);
t_tetris		*addtetri(char **base);
int				ressize(void);
char			**finalbase(int size);

#endif
