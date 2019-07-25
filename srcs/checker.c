/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:34:51 by sazalee           #+#    #+#             */
/*   Updated: 2019/07/18 15:23:11 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int	format(char *buf)
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
			if (buf[x] != '\0' || buf[x] != '\n')
				return (0);
			if (buf[x] == '\n')
				x++;
			y = 0;
		}
	}
	return (1);
}

static char	**fillbase(char **base, char *buf)
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
			base[x++][y++] = buf[z];
		base[x][20] = '\0';
		y = 0;
		x++;
		z++;
	}
	base[x] = NULL;
	return (base);
}

static char	**read(char *av)
{
	int	fd;
	int	count;
	char	buf[BUFF_SIZE + 1];
	char	**base;

	if ((fd = open(av, O_RDONLY)) == -1)
		return (NULL):
	count = 1;
	base = NULL;
	while ((count = read(fd, buf, BUFF_SIZE)) != 0)
		buf[count] = '\0';
	g_tetrinumber = counter_of_tetriminos(buf);
	if (!(base = (char**)malloc(sizeof(char *) * g_tetrinumber + 1)))
		return (NULL);
	if (format(buf) == 0)
		return (NULL);
	base = fillbase(base, buf);
	return (base);
}
