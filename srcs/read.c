/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:39:00 by sazalee           #+#    #+#             */
/*   Updated: 2019/08/01 12:33:50 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			counter_of_tetriminos(char *buf)
{
	int counter;
	int index;
	int numb;

	counter = 0;
	index = 0;
	numb = 0;
	while (buf[index])
	{
		if (buf[index] == '\n')
		{
			numb++;
			if (numb % 5 == 0 && numb != 0)
				counter++;
		}
		index++;
	}
	if (index)
		counter++;
	return (counter);
}

int			format(char *buf)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (buf[x] != '\0')
	{
		while (buf[x] != '\n' && buf[x] != '\0')
			x++;
		if (buf[x] == '\n')
		{
			x++;
			y++;
		}
		if (y == 4)
		{
			if (buf[x] != '\0' && buf[x] != '\n')
				return (0);
			if (buf[x] == '\n')
				x++;
			y = 0;
		}
	}
	return (1);
}

char		**fillbase(char **base, char *buf)
{
	int x;
	int y;
	int z;

	x = 0;
	y = 0;
	z = 0;
	while (x < g_tetrinumber)
	{
		if (!(base[x] = (char*)malloc(sizeof(char) * 20 + 1)))
			return (NULL);
		while (y < 20)
		{
			base[x][y] = buf[z];
			z++;
			y++;
		}
		base[x][20] = '\0';
		y = 0;
		x++;
		z++;
	}
	base[x] = NULL;
	return (base);
}

char		**ft_read(char *av)
{
	int		fd;
	int		count;
	char	buf[BUFF_SIZE + 1];
	char	**base;

	if ((fd = open(av, O_RDONLY)) == -1)
		return (NULL);
	count = 1;
	base = NULL;
	while ((count = read(fd, buf, BUFF_SIZE)) != 0)
		buf[count] = '\0';
	g_tetrinumber = counter_of_tetriminos(buf);
	if (!(base = (char**)malloc(sizeof(char *)
					* counter_of_tetriminos(buf) + 1)))
		return (NULL);
	if (format(buf) == 0)
		return (NULL);
	base = fillbase(base, buf);
	close(fd);
	return (base);
}
