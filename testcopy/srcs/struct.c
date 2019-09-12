/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:27:06 by sazalee           #+#    #+#             */
/*   Updated: 2019/09/12 18:03:38 by sazalee          ###   ########.fr       */
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

t_tetris	*fill_node(char *bufer, t_tetris *new, int numord)
{
	int        i;
	int        j;
	int        k;
	k = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			new->tetrimino[i][j] = bufer[k];
			j++;
			k++;
		}
		k++;
		i++;
	}
	new->alphabet = 'A' + numord;
 	new->x = 0;
	new->y = 0;
	new->next = NULL;
	return (new);
}

t_tetris	*createtri(char *tetrimino, int numord)
{
	t_tetris	*addition;
	int			i;
	
	if (!(addition = (t_tetris *)ft_memalloc(sizeof(t_tetris))) && (!(addition->tetrimino = (char **)ft_memalloc(sizeof(char *) * 4))))
		return (NULL);
	i = 0;
	ft_putstr("OK");
	while (i < 4)
	{
		if (!(addition->tetrimino[i] = ft_strnew(4)))
			return (NULL);
		ft_putstr("KUKU");
		i++;
	}
	ft_putstr("KIRILL");
	return (fill_node(tetrimino, addition, numord));
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
		temp->next = createtri(base[count], count);
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
