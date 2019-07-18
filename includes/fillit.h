/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:18:09 by sazalee           #+#    #+#             */
/*   Updated: 2019/07/15 16:19:49 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 4096
# include "libft.h"

typedef struct	tetristruct
{
	char			**tetrimino;
	char			alphabet;
	int			x;
	int			y;
	struct tetristruct	*next;
}		tetri;
