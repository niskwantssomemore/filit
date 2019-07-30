/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkercont.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:11:31 by sazalee           #+#    #+#             */
/*   Updated: 2019/07/30 14:19:24 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	ft_height_c(char *str)
{
	int index;
	int counter;

	index = 0;
	counter = 0;
	while (str[index])
	{
		while (str[index] && str[index] != '\n')
		{
			if (str[index] == '#')
			{
				counter++;
				while (str[index] && str[index] != '\n')
					index++;
				break ;
			}
			index++;
		}
		if (!str[index])
			break ;
		index++;
	}
	return (counter);
}

int	ft_width_c(char *str)
{
	int index;
	int counter;
	int flag;

	counter = 0;
	flag = 1;
	while (flag < 5)
	{
		index = 0;
		while (index < 4)
		{
			if (str[flag + 5 * index - 1] == '#')
			{
				counter++;
				break ;
			}
			index++;
		}
		flag++;
	}
	return (counter);
}

int	ft_neighbors_c(char *str, int height, int width)
{
	int index;
	int counter;
	int flag;

	index = 0;
	counter = 0;
	flag = 0;
	while (str[index])
	{
		while (str[index] != '\n' && str[index])
		{
			if (str[index] == '#' && height == 2 && width == 2)
			{
				flag = 1;
				return ((threeinarow(str, index, counter, flag) == 8) ? 1 : 0);
			}
			else if (str[index] == '#' && ((height == 1 && width == 3) ||
						(width == 1 && height == 3)))
				return ((threeinarow(str, index, counter, flag) == 6) ? 1 : 0);
			index++;
		}
		index++;
	}
	return (0);
}
