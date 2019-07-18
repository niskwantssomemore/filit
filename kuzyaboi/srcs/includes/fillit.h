/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:17:42 by tstripeb          #+#    #+#             */
/*   Updated: 2019/07/18 15:49:20 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H_
# define _FILLIT_H_
# define BUFF_SIZE 21
# define ERROR "error\n"

# include <unistd.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			tetristruct
{
	char				**tetrimino;
	char				alphabet;
	int					x;
	int					y;
	struct tetristruct	*next;
}						tetri;

int number;

void	ft_error();
char	*ft_read_file(int fd);
int		ft_check_c(char *str, int i);
int		ft_check_l(char *str);
int		ft_height_c(char *str);
int		ft_width_c(char *str);
int		ft_index_plus_one(char *str, int index, int counter, int flag);
int		ft_index_minus_one(char *str, int index, int counter, int flag);
int		ft_index_plus_five(char *str, int index, int counter, int flag);
int		ft_index_minus_five(char *str, int index, int counter, int flag);
int		ft_three_in_a_row(char *str, int index, int counter, int flag);
int		ft_neighbors_c(char *str, int height, int width);
int		ft_check_s(char *str);
int		ft_check(char **tetriminos);





#endif
