/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:18:09 by sazalee           #+#    #+#             */
/*   Updated: 2019/07/18 15:47:44 by sazalee          ###   ########.fr       */
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

#endif
