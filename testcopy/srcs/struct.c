/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:27:06 by sazalee           #+#    #+#             */
/*   Updated: 2019/09/12 17:40:08 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		free_lst(t_tetris *begin)
{
	t_tetris	*ptr;
	
	while (begin != NULL)
	{
		ptr = begin;
		ft_freetime(begin->tetrimino, 4);
		//ft_strdel(&begin->tetrimino[3]);
		begin = begin->next;
		ft_memdel((void **)(&ptr));
	}
}

t_tetris	*createtri(char *tetrimino, int numord)
{
	t_tetris	*addition;
	
	addition = NULL;
	if (!(addition = (t_tetris*)malloc(sizeof(t_tetris))))
	{
		return (NULL);
	}
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
	begin = createtri(base[0], 0);
	temp = begin;
	while (count < g_tetrinumber)
	{
		temp->next = createtri(ft_strsplit(base[count], '\n'), count);
		temp = temp->next;
		count++;
	}
	temp->next = NULL;
	return (begin);
}

int			ressize(void)
{
	int size;
	int k;
	int power;

	size = g_tetrinumber * 4;
	power = 0;
	k = 1;
	while (size > 0)
	{
		size -= k;
		k = k + 2;
		power++;
	}
	return (power);
}

char		**finalbase(int size)
{
	char	**base;
	int		index;
	int		jndex;

	if (!(base = (char **)malloc(sizeof(char *) * size + 1)))
		return (0);
	index = 0;
	while (index < size)
	{
		jndex = 0;
		if (!(base[index] = (char *)malloc(sizeof(char) * size)))
		{
			ft_freetime(base, index - 1);
			return (0);
		}
		while (jndex < size)
		{
			base[index][jndex] = '.';
			jndex++;
		}
		base[index][jndex] = '\0';
		index++;
	}
	base[index] = NULL;
	return (base);
}
