/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:34:51 by sazalee           #+#    #+#             */
/*   Updated: 2019/08/06 14:04:56 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	ft_check_c(char *str, int i)
{
	int grate;
	int pointer;
	int index;
	int carry;

	index = 0;
	grate = 0;
	pointer = 0;
	carry = 0;
	while (str[index])
	{
		if (str[index] == '#')
			grate++;
		else if (str[index] == '.')
			pointer++;
		else if (str[index] == '\n')
			carry++;
		else
			return (0);
		index++;
	}
	if (grate == 4 && pointer == 12 &&
			((i == g_tetrinumber - 1 && carry == 3) || carry == 4))
		return (1);
	return (0);
}

int	ft_check_l(char *str)
{
	int index;
	int flag;

	index = 0;
	flag = 1;
	while (str[index])
	{
		while (flag % 5 != 0 && str[index])
		{
			if (str[index] == '\n')
				return (0);
			index++;
			flag++;
		}
		if (str[index] != '\n')
		{
			if (str[index])
				return (0);
			break ;
		}
		index++;
		flag++;
	}
	return (1);
}

int	ft_check_s(char *str)
{
	int height;
	int width;

	height = ft_height_c(str);
	width = ft_width_c(str);
	if ((height == 1 && width == 4) || (width == 1 && height == 4) ||
			(height == 3 && width == 2) || (width == 3 && height == 2) ||
			(height == 2 && width == 2))
	{
		if (ft_neighbors_c(str, height, width))
			return (1);
	}
	return (0);
}

int	check(char **tetriminos)
{
	int i;

	i = 0;
	while (tetriminos[i])
	{
		if (ft_check_c(tetriminos[i], i))
		{
			if (ft_check_l(tetriminos[i]))
			{
				if (!ft_check_s(tetriminos[i]))
					return (0);
			}
			else
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}
