/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:17:42 by tstripeb          #+#    #+#             */
/*   Updated: 2019/08/05 16:45:53 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 4096
# include <unistd.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_tetris
{
	char			**tetrimino;
	char			alphabet;
	int				x;
	int				y;
	struct s_tetris	*next;
}					t_tetris;

int					g_tetrinumber;

void				ft_error();
char				*ft_read_file(int fd);
int					ft_check_c(char *str, int i);
int					ft_check_l(char *str);
int					ft_height_c(char *str);
int					ft_width_c(char *str);
int					indexplusone(char *str, int index, int counter, int flag);
int					indexminusone(char *str, int index, int counter, int flag);
int					indexplusfive(char *str, int index, int counter, int flag);
int					indexminufive(char *str, int index, int counter, int flag);
int					threeinarow(char *str, int index, int counter, int flag);
int					ft_neighbors_c(char *str, int height, int width);
int					ft_check_s(char *str);
int					check(char **tetriminos);
int					counter_of_tetriminos(char *buf);
int					format(char *buf);
char				**fillbase(char **base, char *buf);
char				**ft_read(char *av);
t_tetris			*createtri(char **tetrimino, int numord);
t_tetris			*addtetri(char **base);
int					ressize(void);
char				**finalbase(int size);
int					tester(t_tetris *begin, char *finalbase, int finalsize);
char				**adder(t_tetris *begin, char **finalbase);
char				**cleaner(t_tetris *begin, char **finalb);
char				**solve(t_tetris *begin, int finalsize, char **finalb);
int					read_check_write(char *av, char **base, t_tetris **begin);

#endif
