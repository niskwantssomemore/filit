/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:27:06 by sazalee           #+#    #+#             */
/*   Updated: 2019/08/01 13:15:21 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetris	*createtri(char **tetrimino, int numord)
{
	t_tetris	*addition;

	addition = NULL;
	if (!(addition = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	addition->tetrimino = tetrimino;
	addition->alphabet = 'A' + numord;
	addition->x = 0;
	addition->y = 0;
	addition->next = NULL;
	return (addition);
}

t_tetris	*addtetri(char **base)
{
	int			count;
	t_tetris	*begin;
	t_tetris	*temp;

	count = 1;
	begin = NULL;
	temp = NULL;
	begin = createtetri(ft_strsplit(base[0], '\n'), count);
	temp = begin;
	while (count < g_tetrinumber)
	{
		temp->next = createtetri(ft_strsplit(base[count], '\n'), count);
		temp = temp->next;
		count++;
	}
	temp->next = NULL;
	return (begin);
}
